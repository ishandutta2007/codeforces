#include<iostream>
#include<cstdio>
using namespace std;
long long a,b,c,t,d,ap,g,num,fo,bb;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	t=min(b,c);
	if (a<t)
	{
		printf("1/1\n");
		return 0;
	}
	d=gcd(b,c);
	ap=6000000000000000000;
	bb=b/d;
	if (ap/bb<=c)
	{
		long long yy=t-1;
		d=gcd(yy,a);
		printf("%lld/%lld\n",yy/d,a/d);
		return 0;
	}
	g=b/d*c;
	num=a/g;fo=a%g;
	long long yy=num*min(b,c)+min(fo+1,min(b,c))-1;
	d=gcd(yy,a);
	printf("%lld/%lld\n",yy/d,a/d);
	return 0;
}