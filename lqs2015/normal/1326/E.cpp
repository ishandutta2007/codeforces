#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,p[333333],q[333333],tree[1111111],lazy[1111111],r,pos[333333];
void pushup(int node)
{
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
void push(int node,int x)
{
	tree[node]+=x;
	lazy[node]+=x;
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
int qry(int x,int l,int r,int node)
{
	if (!x) return 0; 
	if (l==r) return tree[node];
	int mid=(l+r)>>1;
	pushdown(node);
	if (x>mid) return qry(x,mid+1,r,(node<<1)|1);
	return qry(x,l,mid,node<<1);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 1e9;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	pushdown(node);
	return min(query(beg,en,l,mid,node<<1),query(beg,en,mid+1,r,(node<<1)|1)); 
}
bool check(int x)
{
	int y=qry(x-1,1,n,1)-min(query(1,x-1,1,n,1),0);
	if (x==1) y=0;
	return (query(x,n,1,n,1)+y>=qry(x-1,1,n,1));
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=n;i++) scanf("%d",&q[i]);
	for (int i=1;i<=n;i++) pos[p[i]]=i;
	r=n;
	for (int i=1;i<=n;i++)
	{
		printf("%d ",r);
		update(q[i],n,1,n,1,-1);
		while(r>=1 && !check(pos[r]))
		{
			update(pos[r],n,1,n,1,1);
			r--;
		}
	}
	printf("\n");
	return Accepted;
}