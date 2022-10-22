#include<bits/stdc++.h>
#define lson (st[p].ls)
#define rson (st[p].rs)
using namespace std;
const int maxn=300000;
struct node
{
	int ls,rs,sum,tag;
};
struct SegmentTree
{
	int cnt;
	node st[maxn*50+5];
	int New_node(int l,int r)
	{
		cnt++;
		st[cnt].ls=st[cnt].rs=0;
		st[cnt].sum=r-l+1;
		st[cnt].tag=2;
		return cnt;
	}
	void build(int l,int r){cnt=0,New_node(l,r);}
	void up(int p)
	{
		st[p].sum=st[lson].sum+st[rson].sum;
		return;
	}
	void down(int p,int l,int r)
	{
		if(!st[p].tag) return;
		int mid=(l+r)/2;
		int cost=st[p].tag-1;
		if(!st[p].ls) st[p].ls=New_node(l,mid);
		if(!st[p].rs) st[p].rs=New_node(mid+1,r);
		st[lson].tag=st[p].tag;
		st[rson].tag=st[p].tag;
		st[lson].sum=cost*(mid-l+1);
		st[rson].sum=cost*(r-mid);
		st[p].tag=0;
		return;
	}
	void change(int p,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R) 
		{
			st[p].tag=v+1;
			st[p].sum=(r-l+1)*v;
			return;
		}
		down(p,l,r);
		int mid=(l+r)/2;
		if(L<=mid) change(lson,l,mid,L,R,v);
		if(R>mid) change(rson,mid+1,r,L,R,v);
		up(p);
		return;
	}
	int query(int p,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return st[p].sum;
		down(p,l,r);
		int mid=(l+r)/2;
		int sum=0;
		if(L<=mid) sum+=query(lson,l,mid,L,R);
		if(R>mid) sum+=query(rson,mid+1,r,L,R);
		return sum;
	}
}T;
int n,q;
int main()
{
	scanf("%d%d",&n,&q);
	T.build(1,n);
	int k,l,r;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		T.change(1,1,n,l,r,k-1);
		printf("%d\n",T.query(1,1,n,1,n));
	}
	return 0;
}