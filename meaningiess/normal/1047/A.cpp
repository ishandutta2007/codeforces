#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c;cin>>n;
	if (n%3==1) a=1,b=1,c=n-2;
	if (n%3==2) a=1,b=2,c=n-3;
	if (n%3==0) a=1,b=1,c=n-2;
	cout<<a<<' '<<b<<' '<<c;
}