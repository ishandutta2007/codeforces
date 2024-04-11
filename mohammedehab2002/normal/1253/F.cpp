#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int> > e;
vector<pair<int,long long> > v[100005],adj[100005];
int par[100005],col[100005],dp[20][100005],dep[100005];
long long dist[100005],mx[20][100005];
pair<long long,int> mn[100005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y,long long c)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return;
	par[x]=y;
	adj[x].push_back({y,c});
	adj[y].push_back({x,c});
}
void dfs(int node,int p)
{
	dp[0][node]=p;
	dep[node]=dep[p]+1;
	for (int i=1;i<20;i++)
	{
		dp[i][node]=dp[i-1][dp[i-1][node]];
		mx[i][node]=max(mx[i-1][node],mx[i-1][dp[i-1][node]]);
	}
	for (auto u:adj[node])
	{
		if (u.first!=p)
		{
			mx[0][u.first]=u.second;
			dfs(u.first,node);
		}
	}
}
long long lca(int u,int v)
{
	long long ret=0;
	if (dep[u]<dep[v])
	swap(u,v);
	int dist=dep[u]-dep[v];
	for (int i=0;i<20;i++)
	{
		if (dist&(1<<i))
		{
			ret=max(ret,mx[i][u]);
			u=dp[i][u];
		}
	}
	if (u==v)
	return ret;
	for (int i=19;i>=0;i--)
	{
		if (dp[i][u]!=dp[i][v])
		{
			ret=max(ret,max(mx[i][u],mx[i][v]));
			u=dp[i][u];
			v=dp[i][v];
		}
	}
	return max(ret,max(mx[0][u],mx[0][v]));
}
int main()
{
	int n,m,k,q,cn;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	cn=n;
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e.push_back({{a,b},c});
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	for (int i=1;i<=k;i++)
	par[i]=i;
	while (1)
	{
		bool ok=0;
		set<pair<long long,int> > s;
		for (int i=1;i<=k;i++)
		{
			col[i]=find(i);
			s.insert({0,i});
			mn[i]={1e18,0};
		}
		for (int i=k+1;i<=n;i++)
		dist[i]=1e18;
		while (!s.empty())
		{
			auto p=*s.begin();
			s.erase(s.begin());
			if (p.first!=dist[p.second])
			continue;
			for (auto u:v[p.second])
			{
				if (p.first+u.second<dist[u.first])
				{
					dist[u.first]=p.first+u.second;
					col[u.first]=col[p.second];
					s.insert({dist[u.first],u.first});
				}
			}
		}
		for (auto p:e)
		{
			if (col[p.first.first]!=col[p.first.second])
			{
				ok=1;
				long long tmp=dist[p.first.first]+dist[p.first.second]+p.second;
				mn[col[p.first.first]]=min(mn[col[p.first.first]],{tmp,col[p.first.second]});
				mn[col[p.first.second]]=min(mn[col[p.first.second]],{tmp,col[p.first.first]});
			}
		}
		if (!ok)
		break;
		for (int i=1;i<=k;i++)
		Union(col[i],mn[col[i]].second,mn[col[i]].first);
	}
	dfs(1,0);
	while (q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%I64d\n",lca(a,b));
	}
}