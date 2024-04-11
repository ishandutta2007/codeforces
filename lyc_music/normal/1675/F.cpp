// Lynkcat.
// Problem: F. Vlad and Unfinished Business
// URL: https://codeforces.com/contest/1675/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
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
#define N 200005
using namespace std;
poly g;
poly G[N];
int ffa[N];
int son[N];
int siz[N];
int ans;
int n,m,s,t;
void dfs(int k,int fa)
{
	ffa[k]=fa;
	son[k]=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		if (son[u]||u==t)
		{
			son[k]=u;
		}
		siz[k]+=siz[u];
	}
}
void dfs1(int k,int fa)
{
	ans++;
	for (auto u:G[k])
	{
		if (u==fa||!siz[u]||son[k]==u) continue;
		dfs1(u,k);
		ans++;
	}
	if (son[k]) dfs1(son[k],k);
}
void BellaKira()
{
	cin>>n>>m;
	cin>>s>>t;
	ans=0;
	for (int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		g.push_back(x);
		siz[x]++;
	}
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(s,0);
	dfs1(s,0);
	cout<<ans-1<<endl;
	for (int i=1;i<=n;i++)	G[i].clear(),siz[i]=0;
	g.clear();
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}