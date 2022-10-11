#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
vector<pair<int,int> > e;
int dep[200005],p[200005],occ[200005],lg[400005],d[4][4];
pair<int,int> tree[800005],dp[20][400005];
int lca(int u,int v)
{
	if (occ[u]>occ[v])
	swap(u,v);
	int d=lg[occ[v]-occ[u]+1];
	return min(dp[d][occ[u]],dp[d][occ[v]-(1<<d)+1]).second;
}
int dist(int a,int b)
{
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
pair<int,int> merge(pair<int,int> a,pair<int,int> b)
{
	if (a>b)
	swap(a,b);
	if (!a.first)
	return b;
	if (a.first==-1)
	return a;
	vector<int> nn({a.first,a.second,b.first,b.second});
	pair<int,pair<int,int> > mx(0,{0,0});
	for (int i=0;i<4;i++)
	{
		for (int j=i+1;j<4;j++)
		{
			d[i][j]=dist(nn[i],nn[j]);
			d[j][i]=d[i][j];
			mx=max(mx,make_pair(d[i][j],make_pair(i,j)));
		}
	}
	for (int i=0;i<4;i++)
	{
		if (d[i][mx.second.first]+d[i][mx.second.second]!=mx.first)
		return {-1,-1};
	}
	return {nn[mx.second.first],nn[mx.second.second]};
}
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]={val,val};
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=merge(tree[2*node],tree[2*node+1]);
	}
}
int query(int node,int st,int en,pair<int,int> cur)
{
	if (st==en)
	return st+(merge(cur,tree[node]).first!=-1);
	int mid=(st+en)/2;
	auto tmp=merge(cur,tree[2*node]);
	if (tmp.first==-1)
	return query(2*node,st,mid,cur);
	return query(2*node+1,mid+1,en,tmp);
}
void dfs(int node)
{
	if (occ[node]==-1)
	occ[node]=e.size();
	e.push_back({dep[node],node});
	for (int u:v[node])
	{
		dfs(u);
		e.push_back({dep[node],node});
	}
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
		dep[i]=dep[a]+1;
	}
	memset(occ,-1,sizeof(occ));
	dfs(1);
	for (int i=(int)e.size()-1;i>=0;i--)
	{
		dp[0][i]=e[i];
		for (int j=1;j<20;j++)
		{
			dp[j][i]=dp[j-1][i];
			if (i+(1<<(j-1))<e.size())
			dp[j][i]=min(dp[j][i],dp[j-1][i+(1<<(j-1))]);
		}
	}
	for (int i=2;i<=e.size();i++)
	lg[i]=lg[i-1]+!(i&(i-1));
	for (int i=1;i<=n;i++)
	update(1,0,n-1,p[i],i);
	scanf("%d",&q);
	while (q--)
	{
		int t;
		scanf("%d",&t);
		if (t==2)
		printf("%d\n",query(1,0,n-1,{0,0}));
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			swap(p[a],p[b]);
			update(1,0,n-1,p[a],a);
			update(1,0,n-1,p[b],b);
		}
	}
}