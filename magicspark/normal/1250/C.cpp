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
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int f[3005][3005];
int n,m,a[3005][3005];
char c[3005];
string read(){
	scanf("%s",c);return c;
}
struct BIT{
	int f[3005];
	BIT(){memset(f,0,sizeof f);}
	void add(int x,int v){
		while(x<=3004){
			f[x]+=v;
			x+=x&-x;
		}
	}
	int sum(int l,int r){
		int ret=0;
		while(r){
			ret+=f[r];r&=r-1;
		}
		l--;
		while(l){
			ret-=f[l];l&=l-1;
		}
		return ret;
	}
}dif[6006];
vector<int> sub[3005][6006];
int go[3005][3005];
int L[3005],R[3005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string s=" "+read();
		for(int j=1;j<=m;j++){
			a[i][j]=(s[j]=='z');
			go[i][j]=a[i][j];
		}
	}
	for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)if(a[i][j])go[i][j]=go[i+1][j-1]+1;
	ll ans=0;
	for(int i=n;i>=1;i--){
		for(int r=m,l=m;r>=1;r--){
			l=min(l,r);
			while(l>=1&&a[i][l])l--;
			L[r]=l+1;
		}
		for(int l=1,r=1;l<=m;l++){
			r=max(r,l);
			while(r<=m&&a[i][r])r++;
			R[l]=r-1;
		}
		for(int j=1;j<=m;j++){
			if(!a[i][j])continue;
			int len=R[j]-j+1;
			dif[i+j].add(i,1);
			if(i-len+1>0)sub[i-len+1][i+j].push_back(i);
		}
		for(int j=1;j<=m;j++){
			//calc answer of <i,j>
			if(!a[i][j])continue;
			int max_len=min(j-L[j]+1,go[i][j]);
			ans+=dif[i+j].sum(i,i+max_len-1);
		}
		for(int j=1;j<6005;j++){
			for(int p=0;p<sub[i][j].size();p++)dif[j].add(sub[i][j][p],-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}