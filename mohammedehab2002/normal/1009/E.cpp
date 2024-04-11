#include <iostream>
using namespace std;
#define mod 998244353
long long cum[1000005],cumd[1000005],dp[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%I64d",&cum[i]);
		cum[i]=(cum[i]+cum[i-1])%mod;
	}
	long long tmp=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=(cum[i]+cumd[i-1]+tmp)%mod;
		tmp=(2*tmp+cum[i])%mod;
		cumd[i]=(dp[i]+cumd[i-1])%mod;
	}
	printf("%I64d\n",dp[n]);
}