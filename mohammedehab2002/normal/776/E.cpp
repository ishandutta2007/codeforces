#include <iostream>
using namespace std;
#define mod 1000000007
long long phi(long long n)
{
	long long ans=1;
	for (long long i=2;i*i<=n;i++)
	{
		if (n%i==0)
		{
			long long pow=1;
			while (n%i==0)
			{
				pow*=i;
				n/=i;
			}
			ans*=(pow-pow/i);
		}
	}
	if (n!=1)
	ans*=(n-1);
	return ans;
}
int main()
{
	long long n,k;
	cin >> n >> k;
	k=(k+1)/2;
	while (k--)
	{
		n=phi(n);
		if (n==1)
		break;
	}
	cout << n%mod;
}