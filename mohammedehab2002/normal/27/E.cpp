#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> primes;
void sieve(int n)
{
	bool prime[n+1];
	memset(prime,1,sizeof(prime));
	for (int i=2;i<=n;i++)
	{
		if (prime[i])
		{
			primes.push_back(i);
			for (int x=2*i;x<=n;x+=i)
			prime[x]=0;
		}
	}
}
unsigned long long pow_log(long long n,long long exp)
{
    long long ret;
    if(exp==0)
    return 1;
    if (exp==1)
    return n;
    ret=pow_log(n,exp/2);
    if (exp%2==0)
    return ret*ret;
    else
    return ret*ret*n;
}
unsigned long long func(int n,vector<int> s)
{
	if (n==1)
	{
		unsigned long long ans=1;
		sort(s.begin(),s.end());
		reverse(s.begin(),s.end());
		for (int i=0;i<s.size();i++)
		{
			if (log(1ULL<<63)/log(primes[i])<s[i]-1)
			return (1ULL<<63);
			ans*=pow_log(primes[i],s[i]-1);
		}
		return ans;
	}
	unsigned long long ans=(1ULL<<63);
	for (int i=2;i<=n;i++)
	{
		if (n%i==0)
		{
			s.push_back(i);
			ans=min(ans,func(n/i,s));
			s.pop_back();
		}
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	sieve(1000);
	cout << func(n,vector<int>());
}