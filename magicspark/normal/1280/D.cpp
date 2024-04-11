/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
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
//1750pts
int T,n,m;
int dat[3003],sz[3003];
pair<int,int>dp[3003][3003];
int res[3003][3003];
vector<int>g[3003];
pair<int,int>tdp[3003];
void dfs(int x,int par){
	sz[x]=1;bool calc=false;
	dp[x][0]=make_pair(0,dat[x]);
	for(auto to:g[x]){
		if(to!=par){
			dfs(to,x);
			if(!calc){
				for(int i=0;i<=sz[to];i++)dp[x][i]=dp[to][i],dp[x][i].second+=dat[x];
				for(int i=1;i<=sz[to];i++)dp[x][i]=max(dp[x][i],make_pair(res[to][i],dat[x]));
			}else{
				for(int k=sz[x];k>=0;k--){
					for(int i=sz[to];i>=0;i--){
						dp[x][k+i]=max(dp[x][k+i],make_pair(dp[x][k].first+dp[to][i].first,dp[x][k].second+dp[to][i].second));
						if(i)dp[x][k+i]=max(dp[x][k+i],make_pair(res[to][i]+dp[x][k].first,dp[x][k].second));
					}
				}
			}
			calc=true;
			sz[x]+=sz[to];
		}
	}
	for(int i=0;i<=sz[x];i++)dp[x][i].first++;
//	for(int i=0;i<=sz[x];i++){
//		cerr<<x<<" "<<i<<" "<<dp[x][i].first<<" "<<dp[x][i].second<<endl;
//	}
	for(int i=1;i<=sz[x];i++)res[x][i]=dp[x][i-1].first+(dp[x][i-1].second>0);
}
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		memset(dat,0,sizeof dat);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++){
			int x;scanf("%I64d",&x);
			dat[i]-=x;
		}
		for(int i=1;i<=n;i++){
			int x;scanf("%I64d",&x);
			dat[i]+=x;
		}
		for(int i=1;i<n;i++){
			int x,y;scanf("%I64d%I64d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=make_pair(0,-inf);
		dfs(1,-1);
		printf("%I64d\n",res[1][m]-n);
	}
	return 0;
}