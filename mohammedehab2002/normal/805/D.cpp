#include <iostream>
#include <string.h>
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
	string s;
	cin >> s;
	long long ans=0,na=0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='b')
		ans=(ans+pow_log(2,na)-1)%mod;
		else
		na++;
	}
	cout << ans;
}