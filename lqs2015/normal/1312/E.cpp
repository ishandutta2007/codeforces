#include<bits/stdc++.h>
using namespace std;
int n,a[555],dp[555][555],l,r,DP[555];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) dp[i][i]=a[i];
	for (int i=1;i<n;i++)
	{
		for (int j=1;i+j<=n;j++)
		{
			l=j;r=i+j;
			for (int k=l;k<r;k++)
			{
				if (dp[l][k] && dp[l][k]==dp[k+1][r]) 
				{
					dp[l][r]=dp[l][k]+1;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		DP[i]=1e9;
		for (int j=1;j<=i;j++)
		{
			if (dp[j][i]) DP[i]=min(DP[i],DP[j-1]+1);
		}
	}
	printf("%d\n",DP[n]);
	return 0;
}