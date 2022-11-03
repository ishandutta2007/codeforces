#include <iostream>
using namespace std;

int num(int a,int b)
{
	int sum=0;
	while(a>0)
	{
		sum+=(a%b);
		a/=b;
	}
	return sum+a%b;
}
long long gcd(long long a,long long b)
{
    return( (!b)? a : gcd(b,a%b) );
}
int main()
{
	int a,sum=0;
	cin>>a;
	for(int i=2;i<a;i++)
	{
		sum+=num(a,i);
	}
	cout<<sum/gcd(sum,a-2)<<"/"<<(a-2)/(gcd(sum,a-2));
}