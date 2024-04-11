#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n)
{
	for (int i=2;i<=sqrt(n);i++)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int n;
int main()
{
	cin>>n;
	for (int i=1;i<=1000;i++)
	{
		if (!isprime(n*i+1)) 
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}