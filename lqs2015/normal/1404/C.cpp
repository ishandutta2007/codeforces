#include<bits/stdc++.h>
using namespace std;
int n,q,a[333333],can[333333],bit[666666],sz,d[333333],lazy[2222222],pos,ans[333333];
pair<int,int> tree[2222222];
struct query
{
	int x,y,id;
	bool operator < (const query &u) const
	{
		return x<u.x;
	}
}que[333333];
void update(int p,int x)
{
	while(p<=sz)
	{
		bit[p]+=x;
		p+=p&(-p);
	}
}
int query(int p)
{
	int res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
void pushup(int node)
{
	tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		if (can[l]) tree[node]=make_pair(d[l-1]-l+a[l],l);
		else tree[node]=make_pair(1e9,l);
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,(node<<1)|1);
	pushup(node);
}
void push(int node,int x)
{
	tree[node].first+=x;
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
void upd(int x,int l,int r,int node,int y)
{
	if (l==r)
	{
		tree[node].first=y;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,y);
	else upd(x,l,mid,node<<1,y);
	pushup(node);
}
void minu(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		push(node,-1);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(node);
	minu(beg,en,l,mid,node<<1);
	minu(beg,en,mid+1,r,(node<<1)|1);
	pushup(node);
}
void up(int x)
{
	if (!can[x]) return;
	can[x]=0;
	update(x,-1);
	push(1,-1);
	upd(x,1,n,1,1e9);
	while(tree[1].first<0)
	{
		int id=tree[1].second;
		can[id]=0;
		update(id,-1);
		minu(id+1,n,1,n,1);
		upd(id,1,n,1,1e9);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sz=1;
	while(sz<n) sz<<=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=i-d[i-1] && a[i]<=i) can[i]=1;
		d[i]=d[i-1]+can[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (can[i]) update(i,1);
	}
	build(1,n,1);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d",&que[i].x,&que[i].y);
		que[i].id=i;
	}
	sort(que+1,que+q+1);
	pos=0;
	for (int i=1;i<=q;i++)
	{
		while(pos<que[i].x)
		{
			up(pos+1);
			pos++;
		}
		ans[que[i].id]=query(n-que[i].y);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}