#include <iostream>
#include <string.h>
using namespace std;
long long dp[1005][10005],cnt[1005],cost[1005];
int main()
{
	int n,w,b,x;
	scanf("%d%d%d%d",&n,&w,&b,&x);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&cnt[i]);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&cost[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=w;
	for (int i=1;i<=n;i++)
	{
		for (long long j=0;j<10005;j++)
		{
			for (int k=0;k<=min(cnt[i],j);k++)
			{
				if (dp[i-1][j-k]!=-1)
				dp[i][j]=max(dp[i][j],min(dp[i-1][j-k]+x,w+(j-k)*b)-k*cost[i]);
			}
		}
	}
	for (int i=0;i<10005;i++)
	{
		if (dp[n][i]==-1)
		{
			printf("%d",i-1);
			return 0;
		}
	}
}