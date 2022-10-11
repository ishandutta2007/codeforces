#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005],inv[100005];
int arr[100005],stt[100005],ent[100005],dep[100005],tree[3000005],root[100005],lc[3000005],rc[3000005],cur,cn;
void dfs(int node,int p)
{
	stt[node]=++cur;
	dep[node]=dep[p]+1;
	inv[dep[node]].push_back(node);
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
	ent[node]=cur;
}
void build(int node,int st,int en)
{
	tree[node]=(1<<30);
	if (st==en)
	return;
	lc[node]=++cn;
	rc[node]=++cn;
	int mid=(st+en)/2;
	build(lc[node],st,mid);
	build(rc[node],mid+1,en);
}
void update(int node,int node2,int st,int en,int idx)
{
	if (st==en)
	tree[node]=arr[idx];
	else
	{
		int mid=(st+en)/2;
		if (st<=stt[idx] && stt[idx]<=mid)
		{
			lc[node]=++cn;
			rc[node]=rc[node2];
			update(lc[node],lc[node2],st,mid,idx);
		}
		else
		{
			lc[node]=lc[node2];
			rc[node]=++cn;
			update(rc[node],rc[node2],mid+1,en,idx);
		}
		tree[node]=min(tree[lc[node]],tree[rc[node]]);
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return (1<<30);
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return min(query(lc[node],st,mid,l,r),query(rc[node],mid+1,en,l,r));
}
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(r,0);
	root[0]=++cn;
	build(root[0],1,n);
	for (int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		for (int u:inv[i])
		{
			int tmp=root[i];
			root[i]=++cn;
			update(root[i],tmp,1,n,u);
		}
	}
	int q,last=0;
	scanf("%d",&q);
	while (q--)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		x=(x+last)%n+1;
		k=(k+last)%n;
		last=query(root[min(n,dep[x]+k)],1,n,stt[x],ent[x]);
		printf("%d\n",last);
	}
}