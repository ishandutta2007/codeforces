#include<cstdio>
#include<iostream>

using namespace std;

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	return (!b)?a:gcd(b,a%b);
}

int main()
{
	unsigned long long n;
	cin>>n;
	if (n<=2)
	{
		cout<<n<<endl;
		return 0;
	}
	unsigned long long s=n*(n-1);
	for (unsigned long long i=1;i<=n;++i)
	{
		s=max(s,i*n*(n-1)/gcd(i,n*(n-1)));
		s=max(s,i*(n-2)*(n-1)/gcd(i,(n-2)*(n-1)));
	}
	cout<<s<<endl;
	return 0;
}