#include<iostream>
using namespace std;
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
	int n;
	cin>>n;
	long long p=1;
	for (int i=0;i<5;i++)
	{
		p*=(n-i);
	}
	cout<<p*binomial(n,5)<<endl;
	return 0;
}