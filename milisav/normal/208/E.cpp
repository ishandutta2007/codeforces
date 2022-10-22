#include <bits\stdc++.h>
using namespace std;
vector<int> a[200000];
int p[200000];
int d[200000];
int t[200000];
int n;
int m;
int r,q;
vector<pair<int,int> > v[200000][2];
int o[200000];
int g[200000];
vector<int> h[200000];
void dfs_parent(int u,int b)
{
	t[b]=u;
	d[u]=b;
	for(int i=0;i<v[u][0].size();i++)
	{
		if((d[u]-v[u][0][i].first)>0) v[t[(d[u]-v[u][0][i].first)]][1].push_back(make_pair(v[u][0][i].first,v[u][0][i].second));
		else o[v[u][0][i].second]=1;
	}
	for(int i=0;i<a[u].size();i++) dfs_parent(a[u][i],b+1);
}
void dfs_children(int u)
{
	g[d[u]]++;
	for(int i=0;i<v[u][1].size();i++)
	{
		h[u].push_back(g[d[u]+v[u][1][i].first]);
		g[d[u]+v[u][1][i].first]=0;
	}
	for(int i=0;i<a[u].size();i++) dfs_children(a[u][i]);
	for(int i=0;i<h[u].size();i++) o[v[u][1][i].second]=g[d[u]+v[u][1][i].first];
	for(int i=0;i<h[u].size();i++) g[d[u]+v[u][1][i].first]+=h[u][i];
	
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&r);
		p[i+1]=r;
		a[r].push_back(i+1);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&r,&q);
		v[r][0].push_back(make_pair(q,i+1));
	}
	dfs_parent(0,0);
	dfs_children(0);
	for(int i=1;i<=m;i++) printf("%d ",o[i]-1);
	return 0;
}