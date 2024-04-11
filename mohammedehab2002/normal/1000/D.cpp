#include <iostream>
using namespace std;
#define mod 998244353
int arr[1005];
long long ncr[1005][1005],dp[1005],sum;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	ncr[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		ncr[i][0]=1;
		for (int x=1;x<=i;x++)
		ncr[i][x]=(ncr[i-1][x]+ncr[i-1][x-1])%mod;
	}
	dp[n]=1;
	for (int i=n-1;i>=0;i--)
	{
		if (arr[i]<=0)
		continue;
		for (int x=i+arr[i]+1;x<=n;x++)
		dp[i]=(dp[i]+ncr[x-i-1][arr[i]]*dp[x])%mod;
		sum=(sum+dp[i])%mod;
	}
	printf("%I64d",sum);
}