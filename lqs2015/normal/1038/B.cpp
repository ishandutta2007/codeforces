#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
int main()
{
	scanf("%I64d",&n);
	if (n==1) 
	{
		printf("No\n");
		return 0;
	}
	k=n*(n+1)/2;
	for (long long i=2;i<=n;i++)
	{
		if (k%i==0)
		{
			printf("Yes\n");
			printf("%I64d ",n-1);
			for (long long j=1;j<=n;j++)
			{
				if (i!=j) printf("%I64d ",j);
			}
			printf("\n");
			printf("1 %I64d\n",i);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}