// Lynkcat.
// Problem: C. Infected Tree
// URL: https://codeforces.com/contest/1689/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// -----------------------------------------------

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
int dp[N];
int siz[N];
int n;
poly G[N];
void dfs(int k,int fa)
{
	siz[k]=1;
	poly g;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		g.push_back(u);
		dfs(u,k);
		siz[k]+=siz[u];
	}
	while (g.size()!=2) g.push_back(0);
	dp[k]=max({0ll,dp[g[0]]+siz[g[1]]-1,dp[g[1]]+siz[g[0]]-1});
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	cout<<dp[1]<<endl;
	for (int i=1;i<=n;i++) G[i].clear(),siz[i]=0;
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}