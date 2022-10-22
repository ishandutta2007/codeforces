#include <iostream>
using namespace std;

long long kuaism(long long n,long long m,long long mod)
{
	if(n==1)
	{
		return m%mod;
	}
	else if(!n)
	{
		return 1;
	}
	else
	{
		if(n%2)
		{
			long long a=kuaism(n/2,m,mod)%mod;
			return m*a*a%mod;
		}
		else
		{
			long long a=kuaism(n/2,m,mod)%mod;
			return a*a%mod;
		}
	}
}

long long jiec(long long n,long long mod)
{
	if(n==1)
	{
		return 1;
	}
	else 
	{
		return jiec(n-1,mod) % mod*n%mod;
	}
}

int main()
{
	long long n;
	cin>>n;
	if(!n)
	{
		cout<<1<<endl;
		return 0;
	}
	cout<<(kuaism(2*n-1,2,1000000007)+kuaism(n-1,2,1000000007))%1000000007<<endl;
	return 0;
}