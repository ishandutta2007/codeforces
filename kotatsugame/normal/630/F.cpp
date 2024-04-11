#include<iostream>
#define long unsigned long long int
using namespace std;

int main()
{
	int n;
	cin>>n;
	long a5=1,a6;
	long b=1;
	for(int i=n-4;i<=n;i++)
	{
		a5*=i;
		if(a5%(n-i+1)!=0)b*=(n-i+1);
		else
		{
			a5/=(n-i+1);
		}
	}
	a5/=b;
	a6=a5*(n-5)/6;
	cout<<a5+a6+(a6*(n-6)/7)<<endl;
	return 0;
}