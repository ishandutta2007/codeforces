#include<cstdio>
#include<iostream>
using std::max;
const int N=1e5+5;
struct node
{
	int l,r,Max,lazy;
	node *ch[2];
}*root[N];
inline node *new_node(int l,int r)
{
	node *x=new node;
	x->l=l;x->r=r;x->Max=x->lazy=0;
	x->ch[0]=x->ch[1]=NULL;
	return x;
}
inline void push_down(node *x)
{
	if(x->lazy==0)
		return;
	int mid=x->l+x->r>>1;
	if(!x->ch[0])
		x->ch[0]=new_node(x->l,mid);
	if(x->ch[0]->Max<x->lazy)
		x->ch[0]->Max=x->lazy;
	if(x->ch[0]->lazy<x->lazy)
		x->ch[0]->lazy=x->lazy;
	if(!x->ch[1])
		x->ch[1]=new_node(mid+1,x->r);
	if(x->ch[1]->Max<x->lazy)
		x->ch[1]->Max=x->lazy;
	if(x->ch[1]->lazy<x->lazy)
		x->ch[1]->lazy=x->lazy;
	return;
}
void update(node *now,int l,int r,int k)
{
	if(now->l>r||now->r<l)
		return;
	if(now->l>=l&&now->r<=r)
	{
		if(now->Max<k)
			now->Max=k;
		if(now->lazy<k)
			now->lazy=k;
		return;
	}
	int mid=now->l+now->r>>1;
	push_down(now);
	if(!now->ch[0])
		now->ch[0]=new_node(now->l,mid);
	update(now->ch[0],l,r,k);
	if(!now->ch[1])
		now->ch[1]=new_node(mid+1,now->r);
	update(now->ch[1],l,r,k);
	now->Max=max(now->ch[0]->Max,now->ch[1]->Max);
	return;
}
int query(node *now,int l,int r)
{
	if(!now)
		return 0;
	if(now->l>r||now->r<l)
		return 0;
	if(now->l>=l&&now->r<=r)
		return now->Max;
	return max(query(now->ch[0],l,r),query(now->ch[1],l,r));
}
int n,m,ww=1e5;
signed main()
{
	int u,v,w,val;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		root[i]=new_node(0,ww);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		val=query(root[u],0,w-1);
		update(root[v],w,w,val+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if((val=query(root[i],0,ww))>ans)
			ans=val;
	}
	printf("%d\n",ans);
	return 0;
}