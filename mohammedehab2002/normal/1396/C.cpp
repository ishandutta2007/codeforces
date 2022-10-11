#include <bits/stdc++.h>
using namespace std;
int a[1000005];
long long dp[3][1000005],mn[1000005];
int main()
{
	int n;
	long long r1,r2,r3,d;
	scanf("%d%I64d%I64d%I64d%I64d",&n,&r1,&r2,&r3,&d);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	dp[1][n]=1e18;
	for (int i=n-1;i>=0;i--)
	{
		long long c0=min(r1,r3)*a[i]+r3,c1=min(r2+min(r1,r3),min(r1,r3)*a[i]+min(2*r1,r3));
		if (i==n-1)
		{
			dp[0][i]=c0;
			dp[1][i]=c1+2*d;
			dp[2][i]=c0;
		}
		else
		{
			dp[0][i]=min(mn[i+1]+c0+d,dp[1][i+1]+c1+d);
			dp[1][i]=min(dp[0][i+1],dp[2][i+1])+c1+3*d;
			dp[2][i]=dp[2][i+1]+min(c0,c1)+2*d;
		}
		mn[i]=min(dp[0][i],min(dp[1][i],dp[2][i]));
	}
	printf("%I64d",mn[0]);
}