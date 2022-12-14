#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=1000000;
int n,m,a[333333],b[333333],tree[4444444],lazy[4444444],tp,x,y,ans,q;
void pushup(int node)
{
	tree[node]=max(tree[node<<1],tree[(node<<1)|1]);
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
	pushdown(node);
	int mid=(l+r)>>1;
	update(beg,en,l,mid,node<<1,x);
	update(beg,en,mid+1,r,(node<<1)|1,x);
	pushup(node);
}
int query(int l,int r,int node)
{
	if (l==r)
	{
		if (tree[node]>0) return l;
		return -1;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	if (tree[(node<<1)|1]>0) return query(mid+1,r,(node<<1)|1);
	return query(l,mid,node<<1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(1,a[i],1,maxn,1,1);
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		update(1,b[i],1,maxn,1,-1);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1)
		{
			if (a[x]<y) 
			{
				update(a[x]+1,y,1,maxn,1,1);
			}
			else
			{
				update(y+1,a[x],1,maxn,1,-1);
			}
			a[x]=y;
		}
		else
		{
			if (b[x]<y)
			{
				update(b[x]+1,y,1,maxn,1,-1);
			}
			else
			{
				update(y+1,b[x],1,maxn,1,1);
			}
			b[x]=y;
		}
		ans=query(1,maxn,1);
		printf("%d\n",ans);
	}
	return Accepted;
}