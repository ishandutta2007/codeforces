#include<iostream>
using namespace std;
long long a,b,c;
int main()
{
	cin>>a>>b;
	c=(1+a)/2;
	if(b>c) cout<<(b-c)*2<<endl;
	else cout<<2*b-1<<endl;
	return 0;
}