#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int arr[100005],tree[3000005],lc[3000005],rc[3000005],root[100005],cn;
void build(int node,int st,int en)
{
	if (st!=en)
	{
		lc[node]=++cn;
		rc[node]=++cn;
		int mid=(st+en)/2;
		build(lc[node],st,mid);
		build(rc[node],mid+1,en);
	}
}
void update(int node,int node2,int st,int en,int idx)
{
	if (st==en)
	tree[node]=1;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		{
			lc[node]=++cn;
			rc[node]=rc[node2];
			update(lc[node],lc[node2],st,mid,idx);
		}
		else
		{
			rc[node]=++cn;
			lc[node]=lc[node2];
			update(rc[node],rc[node2],mid+1,en,idx);
		}
		tree[node]=tree[lc[node]]+tree[rc[node]];
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (st>r || en<l || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return query(lc[node],st,mid,l,r)+query(rc[node],mid+1,en,l,r);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=n-1;i>=0;i--)
	v[arr[i]].push_back(i);
	build(0,0,n-1);
	for (int i=1;i<=100000;i++)
	{
		for (int x=0;!v[i].empty() && x<k;x++)
		{
			int tmp=root[0];
			root[0]=++cn;
			update(root[0],tmp,0,n-1,v[i].back());
			v[i].pop_back();
		}
	}
	for (int i=1;i<n;i++)
	{
		root[i]=root[i-1];
		if (!v[arr[i-1]].empty())
		{
			root[i]=++cn;
			update(root[i],root[i-1],0,n-1,v[arr[i-1]].back());
			v[arr[i-1]].pop_back();
		}
	}
	int q,ans=0;
	scanf("%d",&q);
	while (q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l=(l+ans)%n;
		r=(r+ans)%n;
		if (l>r)
		swap(l,r);
		ans=query(root[l],0,n-1,l,r);
		printf("%d\n",ans);
	}
}