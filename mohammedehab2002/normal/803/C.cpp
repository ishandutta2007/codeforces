#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	long long n,k,ans=-1;
	scanf("%I64d%I64d",&n,&k);
	if (k>1000000)
	{
		printf("-1");
		return 0;
	}
	for (long long i=1;i*i<=n;i++)
	{
		if (n%i==0)
		{
			if (k*(k+1)/2<=i)
			{
				ans=n/i;
				break;
			}
			if (i*k*(k+1)/2<=n)
			ans=i;
		}
	}
	if (ans!=-1)
	{
		for (long long i=1;i<k;i++)
		printf("%I64d ",i*ans);
		printf("%I64d ",n-ans*k*(k-1)/2);
	}
	else
	printf("-1");
}