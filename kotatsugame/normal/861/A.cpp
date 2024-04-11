#include<iostream>
using namespace std;
long long n,k,m,t;
int main()
{
	cin>>n>>k;t=n;
	m=1;
	for(int i=0;i<k;i++)m*=10;
	while(m%2==0&&t%2==0)
	{
		m/=2;t/=2;
	}
	while(m%5==0&&t%5==0)
	{
		m/=5;t/=5;
	}
	cout<<n*m<<endl;
}