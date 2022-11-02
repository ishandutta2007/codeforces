/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
#define last Last
#define first First
int n,k;
int last[2005],first[2005];
int clast[2005],cfirst[2005];
string s[2005];
int a[2005][2005];
int row[2005],col[2005];
int ans[2005][2005];
int cf[2005][2005];
int get_row(int ban_l,int ban_r){
	return row[n]-row[ban_r]+row[ban_l-1];
}
int get_col(int ban_l,int ban_r){
	return col[n]-col[ban_r]+col[ban_l-1];
}
int main(){
	cin>>n>>k;
	memset(last,-1,sizeof last);
	memset(first,inf,sizeof first);
	memset(clast,-1,sizeof clast);
	memset(cfirst,inf,sizeof cfirst);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].size();j++){
			a[i][j+1]=(s[i][j]=='B');
			if(a[i][j+1])last[i]=max(last[i],j+1),first[i]=min(first[i],j+1),clast[j+1]=max(clast[j+1],i),cfirst[j+1]=min(cfirst[j+1],i);
		}
	}
	for(int i=1;i<=n;i++){
		row[i]=1;
		for(int j=1;j<=n;j++)if(a[i][j])row[i]=0;
	}
	for(int i=2;i<=n;i++)row[i]+=row[i-1];
	for(int j=1;j<=n;j++){
		col[j]=1;
		for(int i=1;i<=n;i++){
			if(a[i][j])col[j]=0;
		}
	}
	for(int i=2;i<=n;i++)col[i]+=col[i-1];
	for(int j=1;j+k-1<=n;j++){
		int rnow=0;
		for(int i=1;i<k;i++)if(last[i]<=j+k-1&&first[i]>=j)rnow++;
		for(int i=k;i<=n;i++){
			if(last[i]<=j+k-1&&first[i]>=j)rnow++;
			ans[i-k+1][j]=get_row(i-k+1,i)+get_col(j,j+k-1)+rnow;
			if(last[i-k+1]<=j+k-1&&first[i-k+1]>=j)rnow--;
		}
	}
	for(int j=1;j<=n;j++){
		int st=max(1,clast[j]-k+1),ed=min(n,cfirst[j]);
		if(st>ed)continue;
		cf[st][j]++;cf[ed+1][j]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cf[i][j]+=cf[i-1][j];
//			cerr<<i<<" "<<j<<" "<<cf[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cf[i][j]+=cf[i][j-1];
		}
	}
	int fans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)fans=max(fans,ans[i][j]+cf[i][min(n,j+k-1)]-cf[i][j-1]);
	cout<<fans<<endl;
	return 0;
}