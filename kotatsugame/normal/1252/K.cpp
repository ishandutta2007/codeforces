#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
long long N;
int main()
{
	cin>>N;
	long long g=N;
	for(long long i=2;i*i<=N;i++)
	{
		if(N%i==0)
		{
			g=gcd(g,i);
			g=gcd(g,N/i);
		}
	}
	cout<<g<<endl;
}