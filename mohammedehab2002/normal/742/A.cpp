#include <iostream>
using namespace std;
long long pow_log(long long n,long long exp,long long mod)
{
    long long ret;
    if(exp==0)
    return 1;
    if (exp==1)
    return n;
    ret=pow_log(n,exp/2,mod);
    if (exp%2==0)
    return (((ret%mod)*(ret%mod))%mod);
    else
    return ((((ret%mod)*(ret%mod))%mod)*n)%mod;
}
int main()
{
	int n;
	cin >> n;
	cout << pow_log(8,n,10);
}