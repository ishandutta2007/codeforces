#include <iostream>
#include <vector>
using namespace std;
#define pn pair<int,pair<int,int> >
int dep[100005],dp[20][100005],n;
vector<int> v[100005];
pn tree[400005];
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
			v=dp[i][v];
			u=dp[i][u];
		}
	}
	return dp[0][u];
}
pn merge(pn a,pn b)
{
	if (a.first==-1)
	return b;
	if (b.first==-1)
	return a;
	int l=lca(a.first,b.first);
	if (l==a.first)
	return a;
	if (l==b.first)
	return b;
	return {l,{a.second.first,b.second.first}};
}
void build(int node,int st,int en)
{
    if (st==en)
    tree[node]={st,{st,st}};
    else
    {
        int mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
}
pn query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return {-1,{-1,-1}};
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return merge(query(2*node,st,mid,l,r),query(2*node+1,mid+1,en,l,r));
}
void dfs(int node)
{
	for (int i=1;i<20;i++)
	{
		if (dp[i-1][node])
		dp[i][node]=dp[i-1][dp[i-1][node]];
	}
	for (int u:v[node])
	{
		dep[u]=dep[node]+1;
		dp[0][u]=node;
		dfs(u);
	}
}
int get(int l,int r,int i)
{
	return merge(query(1,1,n,l,i-1),query(1,1,n,i+1,r)).first;
}
int main()
{
	int q;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		v[p].push_back(i);
	}
	dfs(1);
	build(1,1,n);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		auto p=query(1,1,n,l,r);
		int f=get(l,r,p.second.first),s=get(l,r,p.second.second);
		if (dep[f]>dep[s])
		printf("%d %d\n",p.second.first,dep[f]);
		else
		printf("%d %d\n",p.second.second,dep[s]);
	}
}