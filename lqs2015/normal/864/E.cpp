#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct item
{
	int t,k,p,id;
	bool operator < (const item &a) const 
	{
		return k<a.k;
	}
}a[111];
int n,dp[111][2222],path[111][2222],mxi,mxj,mx;
int ans[111],top;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].k,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=a[i].t;j<a[i].k;j++)
		{
			for (int k=0;k<i;k++)
			{
				if (dp[i][j]<dp[k][j-a[i].t]+a[i].p) 
				{
					dp[i][j]=dp[k][j-a[i].t]+a[i].p;
					mxi=k;
				}
			}
			path[i][j]=mxi;
		}
	}
	mx=-1e9;
	for (int i=1;i<=n;i++)
	{
		for (int j=a[i].t;j<a[i].k;j++)
		{
			if (mx<dp[i][j])
			{
				mx=dp[i][j];
				mxi=i;
				mxj=j;
			}
		}
	}
	if (mx==-1e9)
	{
		printf("0\n0\n");
		return 0;
	}
	printf("%d\n",mx);
	while(mxi>0)
	{
		ans[++top]=a[mxi].id;
		int pos=mxj-a[mxi].t;
		mxi=path[mxi][mxj];
		mxj=pos;
	}
	printf("%d\n",top);
	for (;top;top--)
	{
		printf("%d ",ans[top]);
	}
	printf("\n");
	return 0;
}