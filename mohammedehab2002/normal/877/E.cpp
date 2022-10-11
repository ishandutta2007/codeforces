#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200005];
int l[200005],r[200005],cur;
void dfs(int node)
{
	l[node]=cur++;
	for (int u:v[node])
	dfs(u);
	r[node]=cur-1;
}
int tree[800005],lazy[800005];
void update(int node,int st,int en,int l,int r)
{
	if (lazy[node])
	{
		tree[node]=en-st+1-tree[node];
		if (st!=en)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}
	if (st>r || en<l || r<l)
	return;
	if (st>=l && en<=r)
	{
		tree[node]=en-st+1-tree[node];
		if (st!=en)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		return;
	}
	int mid=(st+en)/2;
	update(2*node,st,mid,l,r);
	update(2*node+1,mid+1,en,l,r);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int st,int en,int l,int r)
{
	if (lazy[node])
	{
		tree[node]=en-st+1-tree[node];
		if (st!=en)
		{
			lazy[2*node]^=1;
			lazy[2*node+1]^=1;
		}
		lazy[node]=0;
	}
	if (st>r || en<l || r<l)
	return 0;
	if (st>=l && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	int p1=query(2*node,st,mid,l,r);
	int p2=query(2*node+1,mid+1,en,l,r);
	return p1+p2;
}
char qu[5];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[a].push_back(i);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if (a)
		update(1,0,n-1,l[i],l[i]);
	}
	int q;
	scanf("%d",&q);
	getchar();
	while (q--)
	{
		int a;
		scanf("%s%d",qu,&a);
		if (qu[0]=='g')
		printf("%d\n",query(1,0,n-1,l[a],r[a]));
		else
		update(1,0,n-1,l[a],r[a]);
	}
}