#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,x,y,t;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	cin>>a>>b>>x>>y;
	t=gcd(x,y);
	x/=t;y/=t;
	cout<<min(a/x,b/y)<<endl;
	return 0;
}