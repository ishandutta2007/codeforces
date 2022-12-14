#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=200001,thre=100001;
int n,q,a[111111],x;
int tree[888888],rush[888888],flip[888888];
char s[11];
void push(int node,int x)
{
	if (flip[node]) flip[node]=0;
	rush[node]=x;tree[node]=x;
}
void fp(int node)
{
	tree[node]^=1;
	if (~rush[node]) rush[node]^=1;
	else flip[node]^=1;
}
void pushdown(int node)
{
	if (~rush[node])
	{
		push(node<<1,rush[node]);
		push((node<<1)|1,rush[node]);
		rush[node]=-1;
	}
	if (flip[node])
	{
		fp(node<<1);
		fp((node<<1)|1);
		flip[node]=0;
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
}
void flp(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en)
	{
		fp(node);
		return;
	}
	pushdown(node);
	int mid=(l+r)>>1;
	flp(beg,en,l,mid,node<<1);
	flp(beg,en,mid+1,r,(node<<1)|1);
}
int query(int x,int l,int r,int node)
{
	if (l==r)
	{
		return tree[node];
	}
	pushdown(node);
	int mid=(l+r)>>1;
	if (x>mid) return query(x,mid+1,r,(node<<1)|1);
	return query(x,l,mid,node<<1);
}
int main()
{
	scanf("%d%d",&n,&q);
	memset(rush,-1,sizeof(rush));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=q;i++)
	{
		scanf("%s%d",s,&x);
		if (s[0]=='<')
		{
			if (x<=0) 
			{
				update(1,x+thre-1,1,maxn,1,1);
				update(-x+thre+1,maxn,1,maxn,1,0);
			}
			else 
			{
				update(1,-x+thre,1,maxn,1,1);
				flp(-x+thre+1,x+thre-1,1,maxn,1);
				update(x+thre,maxn,1,maxn,1,0);
			}
		}
		else
		{
			if (x>=0) 
			{
				update(x+thre+1,maxn,1,maxn,1,1);
				update(1,-x+thre-1,1,maxn,1,0);
			}
			else
			{
				update(-x+thre,maxn,1,maxn,1,1);
				flp(x+thre+1,-x+thre-1,1,maxn,1);
				update(1,x+thre,1,maxn,1,0);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (query(thre+a[i],1,maxn,1)) a[i]=-a[i];
		printf("%d ",a[i]);
	}
	printf("\n");
	return Accepted;
}