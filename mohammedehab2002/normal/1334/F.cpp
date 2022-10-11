#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
long long tree[2000005];
void build(int node,int st,int en)
{
	if (st==en)
	{
		if (st)
		tree[node]=1e18;
	}
	else
	{
		int mid=(st+en)/2;
		build(2*node,st,mid);
		build(2*node+1,mid+1,en);
	}
}
void push(int node)
{
	tree[2*node]+=tree[node];
	tree[2*node+1]+=tree[node];
	tree[node]=0;
}
void update(int node,int st,int en,int l,int r,int val)
{
	if (l<=st && en<=r)
	tree[node]+=val;
	if (en<l || st>r || r<l || (l<=st && en<=r))
	return;
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r,val);
	update(2*node+1,mid+1,en,l,r,val);
}
void update(int node,int st,int en,int idx,long long val)
{
	if (st==en)
	tree[node]=min(tree[node],val);
	else
	{
		push(node);
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
	}
}
long long query(int node,int st,int en,int idx)
{
	if (st==en)
	return tree[node];
	else
	{
		push(node);
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		return query(2*node,st,mid,idx);
		return query(2*node+1,mid+1,en,idx);
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
	scanf("%d",&c[i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	scanf("%d",&b[i]);
	build(1,0,m);
	for (int i=0;i<n;i++)
	{
		int idx=lower_bound(b,b+m+1,a[i])-b;
		long long v=query(1,0,m,idx-1);
		update(1,0,m,0,(c[i]<0? m:idx-1),c[i]);
		if (a[i]==b[idx])
		update(1,0,m,idx,v);
	}
	long long ans=query(1,0,m,m);
	if (ans>1e15)
	printf("NO");
	else
	printf("YES\n%I64d",ans);
}