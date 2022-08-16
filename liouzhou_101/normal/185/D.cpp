#include<cstdio>
#include<iostream>

using namespace std;

long long power(long long x,long long y,long long p)
{
	if (!y) return 1;
	long long t=power(x,y>>1,p);
	t=t*t%p;
	if (y&1) t=t*x%p;
	return t;
}

long long rev(long long x,long long p)
{
	return power(x,p-2,p);
}

long long ex_power(long long x,long long y,long long z,long long p)
{
	if (x%p==0) return 0;
	return power(x,power(y,z,p-1),p);
}

long long solve(long long k,long long l,long long r,long long p)
{
	long long x=ex_power(k,2,l,p);
	if (x==1)
	{
		if (k&1)
			return 2%p;
		else
			return power(2,r-l+1,p);
	}
	else
	{
		long long t=(ex_power(x,2,r-l+1,p)+p-1)*rev(x+p-1,p)%p;
		if (k&1)
			return t*rev(power(2,r-l,p),p)%p;
		else
			return t;
	}
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		long long k,l,r,p;
		scanf("%I64d%I64d%I64d%I64d",&k,&l,&r,&p);
		printf("%I64d\n",solve(k,l,r,p));
	}
	return 0;
}