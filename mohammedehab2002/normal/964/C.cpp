#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000009
int n,k;
string s;
long long pow_log(long long b,int e)
{
	if (!e)
	return 1;
	long long ret=pow_log(b,e/2);
	ret=(ret*ret)%mod;
	if (e%2)
	ret=(ret*b)%mod;
	return ret;
}
long long go(long long a,long long b)
{
	long long ans=0;
	for (int i=0;i<k;i++)
	{
		long long tmp=(pow_log(a,n-i)*pow_log(b,i))%mod;
		if (s[i]=='+')
		ans+=tmp;
		else
		ans-=tmp;
		ans=(ans+mod)%mod;
	}
	long long p1=pow_log(b*pow_log(a,mod-2)%mod,n+1),p2=pow_log(b*(pow_log(a,mod-2))%mod,k);
	if (p2==1)
	return (ans*((n+1)/k))%mod;
	return (((ans*(1-p1+mod))%mod)*pow_log(1-p2+mod,mod-2))%mod;
}
int main()
{
	int a,b;
	cin >> n >> a >> b >> k >> s;
	cout << go(a,b);
}