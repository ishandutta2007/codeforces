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
#define int long long 
#pragma comment("-Wl,--stack=1024000000")
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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n,k,ans[55],dp[55][2][2];
int dfs(int x,int rev,int inv){
	if(~dp[x][rev][inv])return dp[x][rev][inv];
	if(x>=(n+1)/2)return 1;
	int ret=0;
	for(int a=0;a<2;a++){
		for(int b=0;b<2;b++){
			if(x+1==n-x&&a!=b)continue;
			if(ans[x+1]==-1||ans[x+1]==a){
				if(ans[n-x]==-1||ans[n-x]==b){
					if(rev==0||a<=b)if(inv==0||a+b<=1){
						ret+=dfs(x+1,rev&(a==b),inv&(a!=b));
					}
				}
			}
		}
	}
	return dp[x][rev][inv]=ret;
}
signed main(){
	cin>>n>>k;
	memset(dp,-1,sizeof dp);
	memset(ans,-1,sizeof ans);
	if(dfs(0,1,1)<=k){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(dp,-1,sizeof dp);ans[i]=0;
		if(dfs(0,1,1)<=k){
			k-=dfs(0,1,1);ans[i]=1;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
}