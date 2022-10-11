#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
int dist[200005],col[200005],a[200005],b[200005],par[200005],dep[200005],dp[20][200005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x!=y)
	par[x]=y;
}
void dfs(int node,int p)
{
	dep[node]=dep[p]+1;
	dp[0][node]=p;
	for (int i=1;i<20;i++)
	dp[i][node]=dp[i-1][dp[i-1][node]];
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int kth(int u,int k)
{
	for (int i=0;i<20;i++)
	{
		if (k&(1<<i))
		u=dp[i][u];
	}
	return u;
}
int lca(int u,int v)
{
	if (dep[u]<dep[v])
	swap(u,v);
	u=kth(u,dep[u]-dep[v]);
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
int dst(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int getnode(int u,int v)
{
	if (!dist[u])
	return u;
	int l=lca(u,v);
	if (dist[l]<=dep[u]-dep[l])
	{
		int cur=u,d=0;
		for (int i=19;i>=0;i--)
		{
			if (d+(1<<i)>dep[u]-dep[l])
			continue;
			if (dist[dp[i][cur]]>d+(1<<i))
			{
				cur=dp[i][cur];
				d+=(1<<i);
			}
		}
		return col[dp[0][cur]];
	}
	int cur=v,d=0,len=dst(u,v);
	for (int i=19;i>=0;i--)
	{
		if (d+(1<<i)>dep[v]-dep[l])
		continue;
		if (dist[dp[i][cur]]<=len-(d+(1<<i)))
		{
			cur=dp[i][cur];
			d+=(1<<i);
		}
	}
	return col[cur];
}
int main()
{
	int n,k,r,qu;
	scanf("%d%d%d",&n,&k,&r);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	queue<int> q;
	memset(dist,-1,sizeof(dist));
	while (r--)
	{
		int a;
		scanf("%d",&a);
		q.push(a);
		dist[a]=0;
		col[a]=a;
		par[a]=a;
	}
	while (!q.empty())
	{
		int node=q.front();
		q.pop();
		for (int u:v[node])
		{
			if (dist[u]==-1)
			{
				dist[u]=dist[node]+1;
				col[u]=col[node];
				q.push(u);
			}
		}
	}
	for (int i=1;i<n;i++)
	{
		if (dist[a[i]]+dist[b[i]]+1<=k)
		Union(col[a[i]],col[b[i]]);
	}
	dfs(1,0);
	scanf("%d",&qu);
	while (qu--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if (dst(u,v)<=k)
		{
			printf("YES\n");
			continue;
		}
		int a=getnode(u,v),b=getnode(v,u);
		if (dst(u,a)<=k && dst(v,b)<=k && find(a)==find(b))
		printf("YES\n");
		else
		printf("NO\n");
	}
}