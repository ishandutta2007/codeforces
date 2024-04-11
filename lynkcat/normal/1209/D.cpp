#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005 
using namespace std;
int ans,n,m;
poly G[N];
int vis[N];
void dfs(int k,int fa)
{
	ans++;
	vis[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		if (vis[u]) continue;
		dfs(u,k);
	}
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{int x,y;
	cin>>x>>y;
	G[x].push_back(y);
	G[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			dfs(i,0);
			ans--;
		}
	cout<<(m-ans)<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}