#include <iostream>
using namespace std;
#define mod 1000000007
long long calc(long long x)
{
	long long tmp=(x*(x+1))%mod;
	tmp=(tmp*(mod+1)/2)%mod;
	return tmp;
}
long long pow_log(long long x,long long y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
int main()
{
	long long x,k;
	cin >> x >> k;
	if (!x)
	{
		cout << 0;
		return 0;
	}
	long long p=pow_log(2,k);
	long long ans=(p*p)%mod;
	ans=(ans*(x%mod))%mod;
	ans=(ans-calc(p-1)+mod)%mod;
	ans=(ans*2)%mod;
	ans=(ans*pow_log(p,mod-2))%mod;
	cout << ans;
}