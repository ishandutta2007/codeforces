#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
const int N=2e5+5;
int n,m;
char s[N],t[N];
struct node
{
	int l,r,key;
	node *ch[2];
}*root[N];
inline node *new_node(int l,int r)
{
	node *x=new node;
	x->l=l;x->r=r;x->key=0;
	x->ch[0]=x->ch[1]=NULL;
	return x;
}
inline node *copy_node(node *y)
{
	node *x=new node;
	x->l=y->l;x->r=y->r;x->key=y->key;
	x->ch[0]=y->ch[0];x->ch[1]=y->ch[1];
	return x;
}
node *build(int l,int r)
{
	node *x=new_node(l,r);
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	x->ch[0]=build(l,mid);
	x->ch[1]=build(mid+1,r);
	return x;
}
node *update(node *now,int pos)
{
	if(now->l>pos||now->r<pos)
		return now;
	now=copy_node(now);
	if(now->l>=pos&&now->r<=pos)
	{
		now->key=1;
		return now;
	}
	now->ch[0]=update(now->ch[0],pos);
	now->ch[1]=update(now->ch[1],pos);
	return now;
}
int query(node *now,int pos)
{
	if(now->l>pos||now->r<pos)
		return 0;
	if(now->l>=pos&&now->r<=pos)
		return now->key;
	return query(now->ch[0],pos)+query(now->ch[1],pos);
}
inline bool check(int x)
{
	int last=0;
	register int i;
	for(i=1;i<=n;i++)
	{
		if(query(root[x],i))
			continue;
		if(s[i]==t[last+1])
		{
			last++;
			if(last==m)
				return true;
		}
	}
	return false;
}
signed main()
{
	int x;
	register int i;
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	root[0]=build(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		root[i]=update(root[i-1],x);
	}
	int l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}