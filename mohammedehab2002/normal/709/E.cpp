#include <iostream>
#include <vector>
using namespace std;
int n,c,par[400005],sz[400005],dp[400005];
vector<int> v[400005];
int pre(int node,int p)
{
	par[node]=p;
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=pre(u,node);
	}
	return sz[node];
}
int find(int node,int p)
{
	for (int u:v[node])
	{
		if (u!=p && sz[u]>n/2)
		return find(u,node);
	}
	return node;
}
void dfs(int node,int p)
{
	if (p!=c)
	dp[node]=dp[p];
	if (n-sz[p]<=n/2)
	dp[node]=max(dp[node],n-sz[p]);
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	pre(1,0);
	c=find(1,0);
	pre(c,0);
	pair<int,int> mx(-1,-1);
	for (int u:v[c])
	{
		if (mx.first==-1 || sz[u]>sz[mx.first])
		{
			mx.second=mx.first;
			mx.first=u;
		}
		else if (mx.second==-1 || sz[u]>sz[mx.second])
		mx.second=u;
	}
	for (int u:v[c])
	{
		if (u==mx.first && mx.second!=-1)
		dp[u]=sz[mx.second];
		if (u!=mx.first)
		dp[u]=sz[mx.first];
		dfs(u,c);
	}
	for (int i=1;i<=n;i++)
	{
		if (i==c || n-sz[i]-dp[i]<=n/2)
		printf("1 ");
		else
		printf("0 ");
	}
}