#include<iostream>
#include<cstdio>
using namespace std;
int tree[2222222],a[1111111],n,q,sz,l,r,x,y,pos,tp;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
void build(int l,int r,int node)
{
	if (l==r)
	{
		tree[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=gcd(tree[node*2],tree[node*2+1]);
}
int query(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return 0;
	if (l>=beg && r<=en)
	{
		if (tree[node]%x==0) return 0;
		if (l==r) return 1;
		if (tree[node*2]%x && tree[node*2+1]%x) return 2;
		int mid=(l+r)/2;
		if (tree[node*2]%x) return query(beg,en,l,mid,node*2,x);
		return query(beg,en,mid+1,r,node*2+1,x);
	}
	int mid=(l+r)/2;
	return query(beg,en,l,mid,node*2,x)+query(beg,en,mid+1,r,node*2+1,x);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sz=1;
	while(sz<n) sz*=2;
	build(1,sz,1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&tp);
		if (tp==1) 
		{
			scanf("%d%d%d",&l,&r,&x);
			if (query(l,r,1,sz,1,x)<=1) printf("YES\n");
			else printf("NO\n");
		}
		else
		{
			scanf("%d%d",&x,&y);
			pos=sz-1+x;tree[pos]=y;
			while(pos>1)
			{
				pos/=2;
				tree[pos]=gcd(tree[pos*2],tree[pos*2+1]);
			}
		}
	}
	return 0;
}