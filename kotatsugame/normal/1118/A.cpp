#include<iostream>
using namespace std;
main()
{
	int q;
	cin>>q;
	for(;q--;)
	{
		long long n,a,b;
		cin>>n>>a>>b;
		if(b>a*2)b=a*2;
		cout<<(n/2*b+n%2*a)<<endl;
	}
}