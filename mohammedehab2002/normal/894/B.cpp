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
	long long r,c,k;
	cin >> r >> c >> k;
	if (k==-1 && (r%2)!=(c%2))
	cout << 0;
	else
	cout << pow_log(pow_log(2,r-1),c-1);
}