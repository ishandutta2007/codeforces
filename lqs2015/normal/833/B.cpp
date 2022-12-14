#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,dp[55][44444],tree[222222],lazy[222222],res,pre[44444],pp[44444];
int a[44444],ap[44444];
bool used[44444];
void build(int l,int r,int node)
{
	if (l==r) 
	{
		tree[node]=ap[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,node*2);
	build(mid+1,r,node*2+1);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}
void update(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return;
	if (l>=beg && r<=en) 
	{
		lazy[node]++;
		return;
	}
	int mid=(l+r)/2;
	update(beg,en,l,mid,node*2);
	update(beg,en,mid+1,r,node*2+1);
	tree[node]=max(tree[node*2]+lazy[node*2],tree[node*2+1]+lazy[node*2+1]);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return -1e9;
	if (l>=beg && r<=en) return tree[node]+lazy[node];
	int mid=(l+r)/2;
	return max(query(beg,en,l,mid,node*2),query(beg,en,mid+1,r,node*2+1))+lazy[node]; 
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		if (!used[a[i]]) res++;
		dp[1][i]=res;
		used[a[i]]=1;
	}
	for (int i=1;i<=n;i++)
	{
		if (!pre[a[i]]) pp[i]=1;
		else pp[i]=pre[a[i]];
		pre[a[i]]=i;
	}
	for (int i=2;i<=k;i++)
	{
		for (int j=1;j<=n;j++) ap[j]=dp[i-1][j-1];
		build(1,n,1);
		memset(lazy,0,sizeof(lazy));
		for (int j=1;j<=n;j++)
		{
			update(pp[j]+1,j,1,n,1);
			dp[i][j]=query(i,j,1,n,1);
		}
	}
	printf("%d\n",dp[k][n]);
	return 0;
}