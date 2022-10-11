#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define MX 10000000
int nrm[MX+5],lp[MX+5],las[MX+5],a[200005],dp[200005][25];
int tree[800005];
void update(int node,int st,int en,int idx,int val)
{
	if (st==en)
	tree[node]=val;
	else
	{
		int mid=(st+en)/2;
		if (idx<=mid)
		update(2*node,st,mid,idx,val);
		else
		update(2*node+1,mid+1,en,idx,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
int find(int node,int st,int en,int idx)
{
	if (st>idx || tree[node]==en-st+1)
	return -1;
	if (st==en)
	return (tree[node]? -1:st);
	int mid=(st+en)/2;
	int tmp=find(2*node+1,mid+1,en,idx);
	if (tmp!=-1)
	return tmp;
	return find(2*node,st,mid,idx);
}
int main()
{
	nrm[1]=1;
	for (int i=2;i<=MX;i++)
	{
		if (!lp[i])
		{
			for (int j=i;j<=MX;j+=i)
			{
				if (!lp[j])
				lp[j]=i;
			}
		}
		if ((i/lp[i])%lp[i]==0)
		nrm[i]=nrm[i/(lp[i]*lp[i])];
		else
		nrm[i]=nrm[i/lp[i]]*lp[i];
	}
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,k,ans=0;
		scanf("%d%d",&n,&k);
		for (int i=1;i<=4*n;i++)
		tree[i]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=nrm[a[i]];
			las[a[i]]=0;
			for (int j=0;j<=k;j++)
			dp[i][j]=1e9;
		}
		for (int i=1;i<=n;i++)
		{
			update(1,0,n,las[a[i]],0);
			las[a[i]]=i;
			update(1,0,n,i,1);
			int j=i;
			for (int r=0;r<=k;r++)
			{
				if (j)
				j=find(1,0,n,j-1);
				for (int l=r;l<=k;l++)
				dp[i][l]=min(dp[i][l],dp[j][l-r]+1);
			}
			for (int l=1;l<=k;l++)
			dp[i][l]=min(dp[i][l],dp[i][l-1]);
		}
		printf("%d\n",dp[n][k]);
	}
}