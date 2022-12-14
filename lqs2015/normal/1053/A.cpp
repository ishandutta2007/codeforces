#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,k;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
int main()
{
	cin>>n>>m>>k;
	if ((2ll*n*m)%k) 
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	long long d=gcd(2*n,k);
	if (d==1)
	{
		d=k;
		printf("%I64d %I64d\n",0ll,0ll);
		printf("%I64d %I64d\n",n,0ll);
		printf("%I64d %I64d\n",0ll,2ll*m/d);
	}
	else
	{
		printf("%I64d %I64d\n",0ll,0ll);
		printf("%I64d %I64d\n",2ll*n/d,0ll);
		printf("%I64d %I64d\n",0ll,(long long)m*(long long)d/k);
	}
	return 0;
}