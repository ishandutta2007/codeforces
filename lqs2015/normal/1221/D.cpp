#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
long long dp[333333][12],ans;
int n,a[333333],b[333333],test;
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		for (int i=0;i<=n;i++)
		{
			for (int j=0;j<=10;j++) 
			{
				dp[i][j]=1e18;
			}
		}
		dp[0][0]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=10;j++)
			{
				for (int k=0;k<=10;k++)
				{
					if (a[i]+j!=a[i-1]+k)
					{
						dp[i][j]=min(dp[i][j],dp[i-1][k]+1ll*b[i]*j);
					}
				}
			}
		}
		ans=1e18;
		for (int j=0;j<=10;j++) ans=min(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
	return 0;
}