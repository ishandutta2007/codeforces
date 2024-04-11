#include <iostream>
using namespace std;
#define mod 1000000007
long long arr[5000005],dp[5000005];
int main()
{
	for (long long i=2;i<5000005;i++)
	{
		if (!arr[i])
		{
			for (long long x=i;x<5000005;x+=i)
			arr[x]=max(arr[x],i);
		}
	}
	for (int i=2;i<5000005;i++)
	{
		long long tmp=arr[i];
		dp[i]=(tmp*(tmp-1)/2+tmp*dp[i/tmp])%mod;
	}
	long long t,l,r,ans=0,exp=1;
	scanf("%I64d%I64d%I64d",&t,&l,&r);
	for (long long i=l;i<=r;i++)
	{
		ans=(ans+exp*dp[i])%mod;
		exp=(exp*t)%mod;
	}
	printf("%I64d",ans);
}