#include <iostream>
using namespace std;
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
int main()
{
	long long n;
	scanf("%I64d",&n);
	if (n==0)
	{
		printf("1");
		return 0;
	}
	long long tmp=pow_log(4,n);
	long long tmp2=pow_log(2,n-1)*((pow_log(2,n)-1+mod)%mod)%mod;
	printf("%I64d",(tmp-tmp2+mod)%mod);
}