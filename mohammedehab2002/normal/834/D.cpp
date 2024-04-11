#include <iostream>
#include <queue>
using namespace std;
int arr[35005],tree[2000005],lc[2000005],rc[2000005],root[35005],cn;
queue<int> q[35005];
void build(int node,int st,int en)
{
	if (st==en)
	tree[node]=(st==q[arr[st]].front());
	else
	{
		lc[node]=++cn;
		rc[node]=++cn;
		int mid=(st+en)/2;
		build(lc[node],st,mid);
		build(rc[node],mid+1,en);
		tree[node]=tree[lc[node]]+tree[rc[node]];
	}
}
void update(int node,int node2,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]=val;
	else
	{
		lc[node]=lc[node2];
		rc[node]=rc[node2];
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		{
			lc[node]=++cn;
			update(lc[node],lc[node2],st,mid,idx,val);
		}
		else
		{
			rc[node]=++cn;
			update(rc[node],rc[node2],mid+1,en,idx,val);
		}
		tree[node]=tree[lc[node]]+tree[rc[node]];
	}
}
int query(int node,int st,int en,int l,int r)
{
	if (st>r || en<l || l>r)
	return 0;
	if (l<=st && en<=r)
	return tree[node];
	int mid=(st+en)/2;
	int p1=query(lc[node],st,mid,l,r);
	int p2=query(rc[node],mid+1,en,l,r);
	return p1+p2;
}
int n,dp[55][35005];
void solve(int k,int l,int r,int optl,int optr)
{
	if (r<l)
	return;
	int mid=(l+r)/2,opt=optl;
	dp[k][mid]=dp[k-1][optl]+query(root[optl],0,n-1,0,mid-1);
	for (int i=optl+1;i<=min(optr,mid-1);i++)
	{
		int tmp=dp[k-1][i]+query(root[i],0,n-1,0,mid-1);
		if (tmp>dp[k][mid])
		{
			dp[k][mid]=tmp;
			opt=i;
		}
	}
	solve(k,l,mid-1,optl,opt);
	solve(k,mid+1,r,opt,optr);
}
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		q[arr[i]].push(i);
	}
	build(0,0,n-1);
	for (int i=1;i<n;i++)
	{
		root[i]=++cn;
		update(cn,root[i-1],0,n-1,q[arr[i-1]].front(),0);
		q[arr[i-1]].pop();
		if (!q[arr[i-1]].empty())
		{
			int tmp=root[i];
			root[i]=++cn;
			update(cn,tmp,0,n-1,q[arr[i-1]].front(),1);
		}
	}
	for (int i=1;i<=n;i++)
	dp[0][i]=-(1<<30);
	for (int i=1;i<=k;i++)
	solve(i,1,n,0,n);
	int ans=0;
	for (int i=1;i<=k;i++)
	ans=max(ans,dp[i][n]);
	printf("%d",ans);
}