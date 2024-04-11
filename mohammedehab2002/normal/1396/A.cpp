#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	printf("1 %d\n",n);
	for (int i=1;i<=n;i++)
	printf("%I64d ",-1LL*n*a[i]);
	if (n==1)
	{
		printf("\n1 1\n0\n1 1\n0");
		return 0;
	}
	printf("\n1 %d\n",n-1);
	for (int i=1;i<n;i++)
	printf("%I64d ",1LL*(n-1)*a[i]);
	printf("\n2 %d\n",n);
	for (int i=2;i<n;i++)
	printf("0 ");
	printf("%I64d",1LL*(n-1)*a[n]);
}