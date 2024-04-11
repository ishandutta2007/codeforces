#include<iostream>
using namespace std;

bool isprime(int n)
{
	if(n==2)return true;
	else if(n%2==0)return false;
	for(int i=3;i*i<=n;i+=2)if(n%i==0)return false;
	return true;
}

int main()
{
	int n;cin>>n;
	if(isprime(n))
	{
		cout<<1<<endl;
		return 0;
	}
	else if(n%2==0)
	{
		cout<<2<<endl;
		return 0;
	}
	else if(isprime(n-2))
	{
		cout<<2<<endl;
		return 0;
	}
	else
	{
		cout<<3<<endl;
		return 0;
	}
	return 0;
}