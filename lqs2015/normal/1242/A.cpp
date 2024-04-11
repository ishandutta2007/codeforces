#include<bits/stdc++.h>
using namespace std;
long long n;
int x;
int main()
{
	scanf("%lld",&n);
	x=sqrt(n);
	for (int i=2;i<=x;i++)
	{
		if (n%i==0)
		{
			while(n>1 && n%i==0)
			{
				n/=i;
			}
			if (n>1)
			{
				printf("1\n");
			}
			else
			{
				printf("%d\n",i);
			}
			return 0;
		}
	}
	printf("%lld\n",n);
	return 0;
}