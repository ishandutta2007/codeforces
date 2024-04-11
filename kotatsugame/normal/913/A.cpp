#include<iostream>
using namespace std;
long long n,m,a;
main()
{
	cin>>m>>n;
	a=1;
	while(n>=a&&m>0)
	{
		a*=2;
		m--;
	}
	cout<<(n>=a?n%a:n)<<endl;
}