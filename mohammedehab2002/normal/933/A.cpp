#include <iostream>
using namespace std;
int arr[2005],dp[2005][2005][2],cum[2005][2];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		cum[i][0]=cum[i-1][0];
		cum[i][1]=cum[i-1][1];
		cum[i][arr[i]-1]++;
		dp[i][i][0]=1;
		dp[i][i][1]=1;
		for (int x=i+1;x<=n;x++)
		{
			dp[i][x][0]=dp[i][x-1][0];
			dp[i][x][1]=dp[i][x-1][1];
			if (arr[x]==1)
			dp[i][x][0]=max(dp[i][x-1][0],dp[i][x-1][1])+1;
			else
			dp[i][x][1]++;
		}
	}
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		for (int x=i;x<=n;x++)
		{
			ans=max(ans,cum[i-1][0]+dp[i][x][0]+cum[n][0]-cum[x][0]);
			ans=max(ans,cum[i-1][0]+dp[i][x][0]+cum[n][1]-cum[x][1]);
			ans=max(ans,cum[i-1][0]+dp[i][x][1]+cum[n][1]-cum[x][1]);
			ans=max(ans,cum[i-1][1]+dp[i][x][1]+cum[n][1]-cum[x][1]);
		}
	}
	printf("%d",ans);
}