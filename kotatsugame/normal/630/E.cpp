#include<iostream>
using namespace std;
long long a,b,c,d;
main()
{
	cin>>a>>b>>c>>d;
	long long x,y;
	x=y=(d-b)/2;
	x++;
	long long len=(c-a)/2;
	cout<<len*(x+y)+x<<endl;
}