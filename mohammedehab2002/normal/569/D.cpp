#include <iostream>
using namespace std;
#define mod 1000000007
long long dp[4005][4005],ncr[4005][4005];
int main()
{
	int n;
	scanf("%d",&n);
	dp[0][0]=1;
	ncr[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		ncr[i][0]=1;
		for (int c=1;c<=i;c++)
		{
			dp[i][c]=(dp[i-1][c]*c+dp[i-1][c-1])%mod;
			ncr[i][c]=(ncr[i-1][c]+ncr[i-1][c-1])%mod;
		}
	}
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		long long sum=0;
		for (int c=0;c<=i;c++)
		sum=(sum+dp[i][c])%mod;
		ans=(ans+sum*ncr[n][n-i])%mod;
	}
	printf("%I64d",ans);
}