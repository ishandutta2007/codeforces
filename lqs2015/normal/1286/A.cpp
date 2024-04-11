#include<bits/stdc++.h>
using namespace std;
int n,a[111],dp[111][111][2];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			dp[i][j][0]=dp[i][j][1]=1e9;
		}
	}
	if (a[1])
	{
		if (a[1]&1) 
		{
			dp[1][0][1]=0;
		}
		else 
		{
			dp[1][1][0]=0;
		}
	}
	else 
	{
		dp[1][0][1]=dp[1][1][0]=0;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			for (int k=0;k<2;k++)
			{
				if (a[i] && (a[i]&1)!=k) continue;
				if (!k && !j) continue;
				for (int h=0;h<2;h++)
				{
					if (!k) dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][h]+(k!=h));
					else dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][h]+(k!=h));
				}
			}
		}
	}
	printf("%d\n",min(dp[n][n/2][0],dp[n][n/2][1]));
	return 0;
}