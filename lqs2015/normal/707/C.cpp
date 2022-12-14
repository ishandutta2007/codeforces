#include<iostream>
#include<cmath>
using namespace std;
long long n,m,k,p;
int main()
{
	p=1;
	cin>>n;
	while(!(n&1))
	{
		if (n==4)
		{
			cout<<5*p<<" "<<3*p<<endl;
			return 0;
		}
		p*=2;
		n/=2;
	}
	if (n==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	long long s=pow(n,2);
	m=((s-1)/2)*p;
	k=((s+1)/2)*p;
	cout<<m<<" "<<k<<endl;
	return 0;
}