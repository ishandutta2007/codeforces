#include <iostream>
#include <stdio.h>
using namespace std;
int sum(long long x)
{
	int s=0;
	while (x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
int main()
{
    long long n,s;
    scanf("%I64d%I64d",&n,&s);
    long long st=0,en=n+1;
    while (st!=en)
    {
    	long long mid=(st+en)/2;
    	if (mid-sum(mid)<s)
    	st=mid+1;
    	else
    	en=mid;
	}
	printf("%I64d",n-st+1);
}