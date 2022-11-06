#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
const int N=1e6+5;
struct node
{
	int l,r,Max,cMax;
	node *ch[2];
}*root[N];
inline node *new_node(int l,int r)
{
	node *x=new node;
	x->l=l;x->r=r;x->Max=l;x->cMax=0;
	x->ch[0]=x->ch[1]=NULL;
	return x;
}
inline void update(node *x)
{
	if(!x->ch[0]&&!x->ch[1])
		x->Max=x->l,x->cMax=0;
	else if(!x->ch[0])
	{
		if(x->ch[1]->cMax>0)
			x->Max=x->ch[1]->Max,x->cMax=x->ch[1]->cMax;
		else
			x->Max=x->l,x->cMax=0;
	}
	else if(!x->ch[1])
			x->Max=x->ch[0]->Max,x->cMax=x->ch[0]->cMax;
	else
	{
		if(x->ch[1]->cMax>x->ch[0]->cMax)
			x->Max=x->ch[1]->Max,x->cMax=x->ch[1]->cMax;
		else
			x->Max=x->ch[0]->Max,x->cMax=x->ch[0]->cMax;
	}
	return;
}
node *add(node *x,int pos)
{
	if(x->l==x->r)
	{
		x->cMax++;
		return x;
	}
	int mid=(x->l+x->r)>>1;
	if(pos<=mid)
	{
		if(!x->ch[0])
			x->ch[0]=new_node(x->l,mid);
		x->ch[0]=add(x->ch[0],pos);
	}
	else
	{
		if(!x->ch[1])
			x->ch[1]=new_node(mid+1,x->r);
		x->ch[1]=add(x->ch[1],pos);
	}
	update(x);
	return x;
}
node *join(node *x,node *y)
{
	if(!x)
		return y;
	if(!y)
		return x;
	node *z=new_node(x->l,x->r);
	if(x->l==x->r)
	{
		z->cMax=x->cMax+y->cMax;
		delete x;delete y;
		return z;
	}
	z->ch[0]=join(x->ch[0],y->ch[0]);
	z->ch[1]=join(x->ch[1],y->ch[1]);
	delete x;delete y;update(z);
	return z;
}
int n;
int deep[N],ans[N];
int v[N<<1],first[N],next[N<<1];
void dfs(int now,int father)
{
	register int go;
	deep[now]=deep[father]+1;
	root[now]=new_node(1,n);
	for(go=first[now];go;go=next[go])
		if(v[go]!=father)
		{
			dfs(v[go],now);
			root[now]=join(root[now],root[v[go]]);
			root[v[go]]=NULL;
		}
	add(root[now],deep[now]);
	ans[now]=root[now]->Max-deep[now];
	return;
}
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&v[i+n-1],&v[i]);
		next[i]=first[v[i+n-1]];first[v[i+n-1]]=i;
		next[i+n-1]=first[v[i]];first[v[i]]=i+n-1;
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}