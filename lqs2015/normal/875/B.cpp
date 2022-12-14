#include<iostream>
#include<cstdio>
using namespace std;
int n,x,tree[1333333],lazy[1333333];
void update(int l,int r,int beg,int en,int node,int x)
{
	if (r<beg || l>en) return;
	if (l<=beg && r>=en)
	{
		lazy[node]+=x;
		return;
	}
	int mid=(beg+en)/2;
	update(l,r,beg,mid,node*2,x);
	update(l,r,mid+1,en,node*2+1,x);
	tree[node]=max(tree[node*2]+lazy[node*2],tree[node*2+1]+lazy[node*2+1]);
}
int get(int l,int r,int beg,int en,int node)
{
	if (r<beg || l>en) return -1e9;
	if (l<=beg && r>=en) return tree[node]+lazy[node];
	int mid=(beg+en)/2;
	return max(get(l,r,beg,mid,node*2),get(l,r,mid+1,en,node*2+1));
}
int main()
{
	scanf("%d",&n);
	printf("1 ");
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		update(x,x,1,n,1,-1e9);
		update(x+1,n,1,n,1,1);
		if (i!=n)
		{
			printf("%d ",get(1,n,1,n,1)+1);
		}
		else printf("1");
	}
	printf("\n");
	return 0;
}