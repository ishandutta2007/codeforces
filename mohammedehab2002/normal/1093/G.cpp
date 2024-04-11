#include <iostream>
using namespace std;
int tree[32][800005];
void update(int node,int st,int en,int idx,int val,int t)
{
	if (st==en)
	tree[t][node]=val;
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx,val,t);
		else
		update(2*node+1,mid+1,en,idx,val,t);
		tree[t][node]=max(tree[t][2*node],tree[t][2*node+1]);
	}
}
int query(int node,int st,int en,int l,int r,int t)
{
	if (en<l || st>r || r<l)
	return -(1<<30);
	if (l<=st && en<=r)
	return tree[t][node];
	int mid=(st+en)/2;
	return max(query(2*node,st,mid,l,r,t),query(2*node+1,mid+1,en,l,r,t));
}
int n,k,cur[5];
void update(int i)
{
	for (int j=0;j<k;j++)
	scanf("%d",&cur[j]);
	for (int m=0;m<(1<<k);m++)
	{
		int val=0;
		for (int j=0;j<k;j++)
		{
			if (m&(1<<j))
			val+=cur[j];
			else
			val-=cur[j];
		}
		update(1,1,n,i,val,m);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	update(i);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			int i;
			scanf("%d",&i);
			update(i);
		}
		else
		{
			int l,r,tmp=(1<<k)-1,ans=0;
			scanf("%d%d",&l,&r);
			for (int m=0;m<=tmp/2;m++)
			ans=max(ans,query(1,1,n,l,r,m)+query(1,1,n,l,r,(m^tmp)));
			printf("%d\n",ans);
		}
	}
}