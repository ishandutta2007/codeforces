#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5555],dp[5555][5555],mn[5555][5555],k,ans[5555];
int mi(int a,int b)
{
	if (a<b) return 0;
	return a-b+1;
}
int main()
{
	scanf("%d",&n);
	if (n%2) k=n/2+1;
	else k=n/2;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)
	{
		for (int j=1;j<=k;j++) 
		{
			mn[i][j]=1e9;
			dp[i][j]=1e9;
		}
	}
	dp[0][0]=0;
	mn[0][0]=0;
	dp[1][1]=mi(a[2],a[1]);
	mn[1][1]=dp[1][1];
	dp[2][1]=mi(a[1],a[2])+mi(a[3],a[2]);
	mn[2][1]=min(dp[1][1],dp[2][1]);
	for (int i=3;i<=n;i++)
	{
		for (int j=1;j<=k;j++)
		{
			dp[i][j]=mn[i-3][j-1]+mi(a[i-1],a[i]);
			if (j>1) dp[i][j]=min(dp[i][j],dp[i-2][j-1]+mi(min(a[i-1],a[i-2]-1),a[i]));
			if (i!=n) dp[i][j]+=mi(a[i+1],a[i]);
			mn[i][j]=min(mn[i-1][j],dp[i][j]);
		}
	}
	for (int i=1;i<=k;i++)
	{
		printf("%d ",mn[n][i]);
	}
	printf("\n");
	return 0;
}