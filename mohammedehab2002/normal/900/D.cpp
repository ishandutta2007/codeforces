#include <iostream>
using namespace std;
int mob[100005],lp[100005];
#define mod 1000000007
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
bool prime(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
		return 0;
	}
	return 1;
}
int mobius(int x)
{
	int cnt=0;
	for (int i=2;i*i<=x;i++)
	{
		if (x%(i*i)==0)
		return 0;
		if (x%i==0)
		cnt++,x/=i;
	}
	if (x!=1)
	cnt+=prime(x);
	return (cnt%2)? -1:1;
}
int main()
{
	long long ans=0;
	int g,n;
	scanf("%d%d",&g,&n);
	if (n%g)
	{
		printf("0");
		return 0;
	}
	n/=g;
	for (int i=1;i*i<=n;i++)
	{
		if (n%i==0)
		{
			ans=(ans+mobius(n/i)*pow_log(2,i-1)+mod)%mod;
			if (i*i!=n)
			ans=(ans+mobius(i)*pow_log(2,n/i-1)+mod)%mod;
		}
	}
	printf("%I64d",ans);
}