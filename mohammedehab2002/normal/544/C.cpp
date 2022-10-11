#include <iostream>
using namespace std;
int dp[2][505][505],arr[505];
int main()
{
	int n,m,b,mod;
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
	{
	    for (int x=0;x<=m;x++)
		{
			for (int j=0;j<=b;j++)
			dp[i%2][x][j]=0;
		}
		for (int x=1;x<=m;x++)
		{
			for (int j=arr[i];j<=b;j++)
			dp[i%2][x][j]=(dp[!(i%2)][x-1][j-arr[i]]+dp[i%2][x-1][j-arr[i]])%mod;
		}
		for (int x=0;x<=m;x++)
		{
			for (int j=0;j<=b;j++)
			dp[i%2][x][j]=(dp[i%2][x][j]+dp[!(i%2)][x][j])%mod;
		}
	}
	int ans=0;
	for (int i=0;i<=b;i++)
	ans=(ans+dp[n%2][m][i])%mod;
	printf("%d",ans);
}