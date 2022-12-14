#include<iostream>
using namespace std;
long long n,ans;
long long binomial(long long n,long long k)
{
	long long p=1;
	for (int i=0;i<k;i++)
	{
		p*=(n-i);
		p/=(i+1);
	}
	return p;
}
int main()
{
	cin>>n;
	for (long long i=5;i<=7;i++)
	{
		ans+=binomial(n,i);
	}
	cout<<ans<<endl;
	return 0;
}