#include <iostream>
using namespace std;
long long tree[800005];
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]=val;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
long long query(int node,int st,int en,int l,int r)
{
	if (en<l || st>r || r<l)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	return query(2*node,st,mid,l,r)+query(2*node+1,mid+1,en,l,r);
}
int find(int node,int st,int en,long long sum)
{
	if (st==en)
	return st;
	int mid=(st+en)/2;
	if (tree[2*node]>=sum)
	return find(2*node,st,mid,sum);
	return find(2*node+1,mid+1,en,sum-tree[2*node]);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		update(1,0,n-1,i,a);
	}
	while (q--)
	{
		int p,v;
		scanf("%d%d",&p,&v);
		update(1,0,n-1,p-1,v);
		if (!query(1,0,n-1,0,0))
		{
			printf("1\n");
			continue;
		}
		int cur=0,ans=-1;
		while (cur!=n-1)
		{
			int tmp=find(1,0,n-1,2*query(1,0,n-1,0,cur));
			if (query(1,0,n-1,tmp,tmp)==query(1,0,n-1,0,tmp-1))
			{
				ans=tmp+1;
				break;
			}
			cur=tmp;
		}
		printf("%d\n",ans);
	}
}