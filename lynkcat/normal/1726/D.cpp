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
vector<pa>g;
int dep[N],ans[N],lstw[N];
int n,m;
pa E[N];
vector<pa>G[N];
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		if (!dep[u])
		{
			ans[w]=0;
			lstw[u]=w;
			// cout<<k<<"->"<<u<<" "<<w<<endl;
			dfs(u,k);
		} else
		if (dep[u]<dep[k])
		{
			ans[w]=1;
			// cout<<"??"<<w<<" "<<k<<" "<<u<<endl;
			g.push_back(mp(k,w));
		}
	}
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(mp(y,i));
		G[y].push_back(mp(x,i));
		E[i]=mp(x,y);
	}
	g.clear();
	dfs(1,0);
	if (g.size()==3)
	{
		map<int,int>Mp;
		for (auto u:g)
		{
			Mp[E[u.se].fi]++,Mp[E[u.se].se]++;
		}
		if (Mp.size()==3)
		{
			int nw=g[0].fi;
			ans[g[0].se]^=1;
			ans[lstw[nw]]^=1;
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i];
	cout<<endl;
	for (int i=1;i<=m;i++) ans[i]=0;
	for (int i=1;i<=n;i++) G[i].clear(),dep[i]=0;
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}