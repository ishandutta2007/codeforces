#include<bits/stdc++.h>
using namespace std;
int n;
long long a[111111];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	printf("1 1\n");
	printf("%d\n",-a[1]);
	a[1]=0;
	if (n==1)
	{
		printf("1 1\n0\n");
	}
	else
	{
		printf("%d %d\n",2,n);
		for (int i=2;i<=n;i++)
		{
			printf("%lld ",a[i]*(n-1));
			a[i]=a[i]*n;
		}
		printf("\n");
	}
	printf("%d %d\n",1,n);
	for (int i=1;i<=n;i++) printf("%lld ",-a[i]);
	printf("\n");
	return 0;
}