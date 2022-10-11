#include <iostream>
using namespace std;
long long a[150000];
int main()
{
	int n,pos=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		if (a[i]>a[pos] || (i && a[i]==a[pos] && a[i]!=a[i-1]))
		pos=i;
	}
	if (a[pos]==a[(pos-1+n)%n])
	{
		if (a[pos])
		printf("NO");
		else
		{
			printf("YES\n");
			for (int i=0;i<n;i++)
			printf("1 ");
		}
		return 0;
	}
	for (int i=(pos-1+n)%n;i!=pos;i=(i-1+n)%n)
	a[i]+=(1+(i==(pos-1+n)%n))*a[(i+1)%n];	
	printf("YES\n");
	for (int i=0;i<n;i++)
	printf("%I64d ",a[i]);
}