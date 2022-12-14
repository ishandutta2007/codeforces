#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[1111111],b[1111111],pw[1111111],sum[1111111],dp[1111111],gg,ps;
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=n;i++) b[i]=(b[i-1]+a[i])%mod;
	pw[0]=(mod+1)/2;
	for (long long i=1;i<=n;i++) pw[i]=pw[i-1]*((mod+1)/2)%mod;
	for (long long i=1;i<=n;i++) sum[i]=(sum[i-1]+pw[i]*b[i])%mod;
	ps=1;
	for (long long i=1;i<=n;i++) ps=ps*2%mod;
	for (long long i=1;i<=n;i++)
	{
		dp[i]=(sum[i]+gg+pw[i]*b[i])%mod;
		gg=gg*((mod+1)/2)%mod;
		gg=(gg+dp[i]*((mod+1)/2))%mod;
	}
	printf("%I64d\n",(dp[n]*ps%mod));
	return 0;
}