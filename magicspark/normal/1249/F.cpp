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
#pragma comment(" -Wl,--stack=1024000000")
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
int dp[255][255],tdp[255];
int n,k,a[255];
vector<int>g[255];
void dfs(int x,int par){
	dp[x][0]=a[x];
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par)dfs(g[x][i],x);
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]==par)continue;	
		int son=g[x][i];
		dp[x][0]+=dp[son][k];
		memset(tdp,0,sizeof tdp);
		for(int j=1;j<=k+1;j++){
			for(int l=1;l<=k+1;l++){
				if(j+l>k)tdp[min(j,l)]=max(tdp[min(j,l)],dp[x][l]+dp[son][j-1]);
			}
		}
		for(int j=1;j<=k+1;j++)dp[x][j]=tdp[j];
	}
//	for(int i=0;i<=k+1;i++){
//		cerr<<x<<" "<<i<<" "<<dp[x][i]<<endl;
//	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	cout<<*max_element(dp[1],dp[1]+k+2)<<endl;
	return 0;
}