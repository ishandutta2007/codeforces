#include<cstdio>
#include<iostream>

using namespace std;

long long n,a,b,c,p=1000000009;

int main()
{
	a=c=1;
	b=2;
	for (cin>>n;n-=2;)
	{
		(b+=4*c)%=p;
		a=(2*a+3)%p;
		(c*=a)%=p;
	}
	cout<<(b*b+1)*2%p<<endl;
	return 0;
}