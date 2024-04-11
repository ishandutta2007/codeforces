#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
int dp[100005],cnt[100005];
long long pow_log(long long n,long long exp)
{
    long long ret;
    if (exp==0)
    return 1;
    if (exp==1)
    return n;
    ret=pow_log(n,exp/2);
    if (exp%2==0)
    return (((ret%mod)*(ret%mod))%mod);
    else
    return ((((ret%mod)*(ret%mod))%mod)*n)%mod;
}
int main()
{
	dp[1]=-1;
	for (int i=2;i<100005;i++)
	{
		int a=i;
		for (int x=2;x*x<=i;x++)
		{
			if (i%x==0)
			{
				if ((i/x)%x==0)
				{
					a=1;
					break;
				}
				if (a==i)
				a=x;
			}
		}
		dp[i]=-dp[i/a];
	}
	int n;
	scanf("%d",&n);
	for (int x=0;x<n;x++)
	{
		int a;
		scanf("%d",&a);
		for (int i=1;i*i<=a;i++)
		{
			if (a%i==0)
			{
				cnt[i]++;
				if (i*i!=a)
				cnt[a/i]++;
			}
		}
	}
	long long ans=0;
	for (int i=2;i<100005;i++)
	ans=(ans+(pow_log(2,cnt[i])-1)*dp[i]+mod)%mod;
	printf("%I64d",(pow_log(2,n)-ans-1+mod)%mod);
}