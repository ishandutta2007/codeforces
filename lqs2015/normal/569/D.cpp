#include<iostream>
using namespace std;
const long long mod=1e9+7;
long long dp[4011][4011],c[4011][4011],n,sum[4011],ans;
int main()
{
	cin>>n;
	for (int i=0;i<=n;i++) c[i][0]=1;
	for (int i=1;i<=n;i++) c[0][i]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	dp[0][0]=1;
	sum[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%mod;
			sum[i]=(sum[i]+dp[i][j])%mod;
		}
	}
	for (int i=0;i<n;i++)
	{
		ans=(ans+c[n][i]*sum[i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}