#include<bits/stdc++.h>
using namespace std;
int a[333333],n,l,r,mid,pre[333333];
struct T
{
	int tree[2222222];
	void build(int l,int r,int node,int a[])
	{
		if (l==r)
		{
			tree[node]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,node<<1,a);
		build(mid+1,r,(node<<1)|1,a);
		tree[node]=max(tree[(node<<1)|1],tree[node<<1]);
	}
	int query(int beg,int en,int l,int r,int node)
	{
		if (l>en || r<beg) return -1e9;
		if (l>=beg && r<=en) return tree[node];
		int mid=(l+r)>>1;
		return max(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
	}
}t1,t2;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		a[i+n]=a[i+2*n]=a[i];
	}
	t1.build(1,3*n,1,a);
	for (int i=1;i<=3*n;i++)
	{
		l=1;r=i;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (t1.query(mid,i,1,3*n,1)>2*a[i]) l=mid+1;
			else r=mid-1;
		}
		pre[i]=r;
	}
	t2.build(1,3*n,1,pre);
	for (int i=1;i<=n;i++)
	{
		l=i;r=3*n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if (t2.query(i,mid,1,3*n,1)>=i) r=mid-1;
			else l=mid+1;
		}
		if (l>3*n) printf("-1 ");
		else printf("%d ",l-i);
	}
	printf("\n");
	return 0; 
}