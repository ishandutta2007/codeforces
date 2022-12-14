#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,len,h;
int a[222222],b[222222],tree[888888],lazy[888888],bd[222222],sz,cur,ans;
void build(int l,int r,int node)
{
	if (l==r) 
	{
		if (l<=len) tree[node]=-l;
		else tree[node]=1e9;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
void pushdown(int node)
{
	if (lazy[node])
	{
		tree[node*2]+=lazy[node];tree[node*2+1]+=lazy[node];
		lazy[node*2]+=lazy[node];lazy[node*2+1]+=lazy[node];
		lazy[node]=0;
	}
}
void update(int beg,int en,int l,int r,int node,int x)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		tree[node]+=x;
		lazy[node]+=x;
		return;
	}
	pushdown(node);
	int mid=(l+r)/2;
	update(beg,en,l,mid,node*2,x);
	update(beg,en,mid+1,r,node*2+1,x);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}
int findpos(int x)
{
	int pos=lower_bound(bd+1,bd+len+2,x+1)-bd;
	return len+3-pos;
}
int main()
{
	scanf("%d%d%d",&n,&len,&h);
	sz=1;
	while(sz<len) sz*=2;
	build(1,sz,1);
	for (int i=1;i<=len;i++)
	{
		scanf("%d",&a[i]);
		bd[i]=h-a[i];
	}
	bd[len+1]=-1e9;
	sort(bd+1,bd+len+2);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=len;i++)
	{
		cur=findpos(b[i]);
		update(cur,len,1,sz,1,1);
	}
	if (tree[1]>=0) ans++;
	for (int i=len+1;i<=n;i++)
	{
		cur=findpos(b[i-len]);
		update(cur,len,1,sz,1,-1);
		cur=findpos(b[i]);
		update(cur,len,1,sz,1,1);
		if (tree[1]>=0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}