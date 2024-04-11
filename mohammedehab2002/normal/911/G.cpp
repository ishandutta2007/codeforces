#include <iostream>
#include <vector>
using namespace std;
struct query
{
	int t,x,y;
	query(int tt,int xx,int yy)
	{
		t=tt;
		x=xx;
		y=yy;
	}
};
vector<int> tree[800005];
vector<query> v[200005];
int arr[200005];
void build(int node,int st,int en)
{
	for (int i=0;i<=100;i++)
	tree[node].push_back(i);
	if (st!=en)
	{
		int mid=(st+en)/2;
		build(2*node,st,mid);
		build(2*node+1,mid+1,en);
	}
}
void update(int node,int st,int en,query q)
{
	if (st==en)
	tree[node][q.x]=q.y;
	else
	{
		int mid=(st+en)/2;
		if (st<=q.t && q.t<=mid)
		update(2*node,st,mid,q);
		else
		update(2*node+1,mid+1,en,q);
		for (int i=0;i<=100;i++)
		tree[node][i]=tree[2*node+1][tree[2*node][i]];
	}
}
int main()
{
	int n,q;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	scanf("%d",&q);
	for (int i=0;i<q;i++)
	{
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		v[l].push_back(query(i,x,y));
		v[r+1].push_back(query(i,x,x));
	}
	build(1,0,q-1);
	for (int i=1;i<=n;i++)
	{
		for (auto x:v[i])
		update(1,0,q-1,x);
		printf("%d ",tree[1][arr[i]]);
	}
}