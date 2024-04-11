#include <iostream>
using namespace std;
#define mod 1000000007
int dp[2005][2005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	dp[0][0]=1;
	for (int i=0;i<2*n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
			if (j)
			dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
			if (i%2 && j+i<=2*n)
			ans=(ans+dp[i][j])%mod;
		}
	}
	printf("%d",ans);
}