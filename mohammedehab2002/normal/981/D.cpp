#include <iostream>
#include <string.h>
using namespace std;
int n,k;
long long arr[55];
bool dp[55][55];
bool check(long long ans)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=n;j++)
		{
			long long sum=0;
			for (int l=j;l>0;l--)
			{
				sum+=arr[l];
				if ((sum&ans)==ans)
				dp[i][j]|=dp[i-1][l-1];
			}
		}
	}
	return dp[k][n];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&arr[i]);
	long long ans=0;
	for (int i=60;i>=0;i--)
	{
		ans^=(1LL<<i);
		if (!check(ans))
		ans^=(1LL<<i);
	}
	printf("%I64d",ans);
}