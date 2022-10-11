#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
vector<int> v[100005];
bool del[100005];
int sz[100005];
void pre(int node,int p)
{
	sz[node]=1;
	for (int u:v[node])
	{
		if (!del[u] && u!=p)
		{
			pre(u,node);
			sz[node]+=sz[u];
		}
	}
}
int find(int node,int p,int n)
{
	for (int u:v[node])
	{
		if (!del[u] && u!=p && sz[u]>n/2)
		return find(u,node,n);
	}
	return node;
}
int par[100005];
void dfs(int node,int p)
{
	pre(node,0);
	int c=find(node,0,sz[node]);
	par[c]=p;
	del[c]=1;
	for (int u:v[c])
	{
		if (!del[u])
		dfs(u,c);
	}
}
int dp[20][100005],dep[100005];
void dfs2(int node,int p)
{
	if (p)
	{
		dp[0][node]=p;
		dep[node]=dep[p]+1;
	}
	for (int u:v[node])
	{
		if (u!=p)
		dfs2(u,node);
	}
}
int lca(int u,int v)
{
	if (dep[u]<dep[v])
	swap(u,v);
	int dist=dep[u]-dep[v];
	for (int i=0;i<20;i++)
	{
		if (dist&(1<<i))
		u=dp[i][u];
	}
	if (u==v)
	return u;
	for (int i=19;i>=0;i--)
	{
		if (dp[i][u]!=dp[i][v])
		{
			u=dp[i][u];
			v=dp[i][v];
		}
	}
	return dp[0][u];
}
int dist(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int ans[100005];
void update(int node)
{
	int cur=node;
	while (cur)
	{
		ans[cur]=min(ans[cur],dist(node,cur));
		cur=par[cur];
	}
}
int query(int node)
{
	int cur=node,ret=(1<<30);
	while (cur)
	{
		ret=min(ret,ans[cur]+dist(node,cur));
		cur=par[cur];
	}
	return ret;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	memset(dp,-1,sizeof(dp));
	dfs2(1,0);
	for (int i=1;i<20;i++)
	{
		for (int x=1;x<=n;x++)
		{
			if (dp[i-1][dp[i-1][x]]!=-1)
			dp[i][x]=dp[i-1][dp[i-1][x]];
		}
	}
	for (int i=1;i<=n;i++)
	ans[i]=(1<<30);
	update(1);
	while (q--)
	{
		int t,u;
		scanf("%d%d",&t,&u);
		if (t==1)
		update(u);
		else
		printf("%d\n",query(u));
	}
}