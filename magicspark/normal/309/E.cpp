/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,l[2005],r[2005];
int lmt[2005],cnt[2005];
int ans[2005],tot,vis[2005];
bool check(int len){
	memset(vis,0,sizeof vis);
	tot=0;
	for(int i=1;i<=n;i++)lmt[i]=n+2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(!vis[j])lmt[j]--;
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++)if(!vis[j])cnt[lmt[j]]++;
		for(int j=1;j<=n;j++)cnt[j]+=cnt[j-1];
		for(int j=1;j<=n;j++)if(cnt[j]>j)return false;
		int ub=n+5;
		for(int j=1;j<=n;j++)if(cnt[j]==j){
			ub=j;break;
		}
		int best=-1;
		for(int j=1;j<=n;j++)if(!vis[j]&&lmt[j]<=ub){
			if(best==-1)best=j;
			else if(r[best]>r[j])best=j;
		}
		ans[++tot]=best;vis[best]=1;
		for(int j=1;j<=n;j++){
			if(max(l[j],l[best])<=min(r[j],r[best])){
				lmt[j]=min(lmt[j],len);
			}
		}
	}
	return true;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
	int L=-1,R=n;
	while(R-L>1){
		int mid=(L+R)/2;
		if(check(mid))R=mid;
		else L=mid;
	}
	check(R);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	return 0;
}