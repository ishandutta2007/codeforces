// Lynkcat.
// Problem: E. Unordered Swaps
// URL: https://codeforces.com/contest/1682/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define N 200005
using namespace std;
poly G[N];
int n,m;
map<pa,int>Mp;
int p[N];
int id[N];
int vis[N];
int ffa[N];
vector<pa>ans;
poly Eg[N];
int ru[N];
void dfs(int k,int fa)
{
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		ans.push_back(mp(k,u));
	}
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>p[i];
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
		if (x>y) swap(x,y);
		Mp[mp(x,y)]=i;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			int now=i;
			poly g;
			int tot=0;
			while (!vis[now])
			{
				g.push_back(now);
				id[now]=tot++;
				vis[now]=1;
				now=p[now];
			}
			for (auto u:g)
			{
				int nw=inf,lst=0;
				for (auto v:G[u])
				{
					if ((id[u]+tot-id[v])%tot<nw)
					{
						nw=(id[u]+tot-id[v])%tot;
						lst=v;
					}
				}
				sort(G[u].begin(),G[u].end(),[&](int x,int y)
				{
					return (id[x]+tot-id[u])%tot<(id[y]+tot-id[u])%tot;
				});
				for (int j=1;j<G[u].size();j++)
				{
					int x=Mp[mp(min(u,G[u][j]),max(u,G[u][j]))];
					int y=Mp[mp(min(u,G[u][j-1]),max(u,G[u][j-1]))];
					Eg[y].push_back(x);ru[x]++;
				}
			}
		}
	queue<int>q;
	for (int i=1;i<=m;i++)
		if (!ru[i]) q.push(i);
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for (auto v:Eg[u])
		{
			ru[v]--;
			if (!ru[v]) q.push(v);
		}
	}
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}