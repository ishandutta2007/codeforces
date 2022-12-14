#include<bits/stdc++.h>
using namespace std;
int n,a[222222],tree[888888],dep[222222],mn,num,l,r,mid,lazy[888888];
pair<int,int> mtree[888888];
pair<int,int> query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return make_pair(1e9,1e9);
	if (l>=beg && r<=en) return mtree[node];
	int mid=(l+r)>>1;
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1));
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		mtree[node]=make_pair(a[l],l);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	mtree[node]=min(mtree[node<<1],mtree[(node<<1)|1]);
}
void build2(int l,int r,int d)
{
	int x=query(l,r,1,n,1).second;
	dep[x]=d;
	if (l<x) build2(l,x-1,d+1);
	if (x<r) build2(x+1,r,d+1);
}
void pushup(int node)
{
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
}
void build3(int l,int r,int node)
{
	if (l==r) 
	{
		tree[node]=dep[l];
		return;
	}
	int mid=(l+r)>>1;
	build3(l,mid,node<<1);
	build3(mid+1,r,(node<<1)|1);
	pushup(node);
}
void push(int node,int x)
{
	lazy[node]+=x;
	tree[node]+=x;
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node<<1,lazy[node]);
		push((node<<1)|1,lazy[node]);
		lazy[node]=0;
	}
}
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		push(node,x);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
void upd(int x,int l,int r,int node,int y)
{
	if (l==r)
	{
		tree[node]=y;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
	else upd(x,l,mid,node<<1,y);
	pushup(node);
}
stack<int> s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n,1);
	build2(1,n,1);
	build3(1,n,1);
	mn=tree[1];num=0;
	for (int i=1;i<=n;i++)
	{
		while(!s.empty() && s.top()>=a[i]) s.pop();
		s.push(a[i]);
	}
	for (int i=1;i<n;i++)
	{
		if (query(i+1,n,1,n,1).first<a[i])
		{
			l=i+1;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(i+1,mid,1,n,1).first>a[i]) l=mid+1;
				else r=mid-1;
			}
			update(i+1,r,1,n,1,-1);
		}
		else 
		{
			l=1;r=i-1;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(1,mid,1,n,1).first>a[i]) l=mid+1;
				else r=mid-1;
			}
			update(i+1,n,1,n,1,-1);
			update(1,r,1,n,1,-1);
		}
		if (query(1,i-1,1,n,1).first<a[i])
		{
			l=1;r=i-1;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(mid,i-1,1,n,1).first>a[i]) r=mid-1;
				else l=mid+1;
			}
			update(l,i-1,1,n,1,1);
		}
		else
		{
			l=i+1;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(mid,n,1,n,1).first>a[i]) r=mid-1;
				else l=mid+1;
			}
			update(l,n,1,n,1,1);
			update(1,i-1,1,n,1,1);
		}
		while(!s.empty() && s.top()>=a[i]) s.pop();
		s.push(a[i]);
		upd(i,1,n,1,(int)s.size());
		if (tree[1]<mn)
		{
			mn=tree[1];
			num=i;
		} 
	}
	printf("%d %d\n",mn,num);
	return 0;
}