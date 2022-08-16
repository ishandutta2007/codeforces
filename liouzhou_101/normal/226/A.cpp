#include<cstdio>
#include<iostream>

using namespace std;

long long n,m;

long long power(long long x,long long p)
{
	if (!p) return 1;
	long long t=power(x,p/2);
	t=t*t%m;
	if (p&1) t=t*x%m;
	return t;
}

int main()
{
	cin>>n>>m;
	cout<<((power(3,n)-1)%m+m)%m<<endl;
	return 0;
}