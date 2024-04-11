/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
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
inline int Rand(){return rand()*32768+rand();}
int n,m;
int msk[20];
vector<pair<int,int> >g[20],gg[20];
ll dp[19][1<<18],pre[19][1<<18],cost[1<<18],o[18],mx=0;
int dfs(int x){
	int ret=1;
	for(auto to:g[x]){
		ret=max(ret,dfs(to.first)+1);
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;x--;y--;
		g[y].push_back(make_pair(x,w));
		gg[x].push_back(make_pair(y,w));
		msk[x]|=1<<y;
	}
	for(int i=0;i<n;i++){
		mx=max(mx,(ll)dfs(i));
	}
	for(int i=0;i<n;i++){
		for(auto p:g[i]){
			cost[1<<i]-=p.second;
		}
		for(auto p:gg[i]){
			cost[1<<i]+=p.second;
		}
	}
	for(int i=1;i<(1<<n);i++){
		cost[i]=cost[i&-i]+cost[i-(i&-i)];
	}
	memset(dp,inf,sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<=mx;i++){
		for(int mask=0;mask<(1<<n);mask++)if(dp[i][mask]<1e18){
			int can=0;
			for(int j=0;j<n;j++){
				if(mask&(1<<j))continue;
				if((mask&msk[j])!=msk[j])continue;
				can|=(1<<j);
			}
			for(int sub=can;sub;sub=(sub-1)&can){
				if(dp[i][mask]+cost[sub]*i<dp[i+1][mask|sub]){
					dp[i+1][mask|sub]=dp[i][mask]+cost[sub]*i;
					pre[i+1][mask|sub]=sub;
				}
			}
		}
	}
	ll ans=1e18;
	for(int i=0;i<=n;i++)ans=min(ans,dp[i][(1<<n)-1]);
	int pos=-1;
	for(int i=0;i<=n;i++){
		if(dp[i][(1<<n)-1]==ans){
			pos=i;
		}
	}
	int cur=(1<<n)-1;
	while(pos){
		int del=pre[pos][cur];
		for(int i=0;i<n;i++){
			if(del&(1<<i))o[i]=pos;
		}
		cur^=del;pos--;
	}
	for(int i=0;i<n;i++)cout<<o[i]<<" ";
	return 0;
}