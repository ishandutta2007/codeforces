#include <iostream>
using namespace std;
int x[100005],k[100005];
long long a[100005],b[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&b[i]);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	for (int i=2;i<=n;i++)
	scanf("%d%d",&x[i],&k[i]);
	for (int i=n;i>1;i--)
	{
		if (a[i]>b[i])
		{
			if (1.0*(a[i]-b[i])*k[i]>1e17)
			{
				printf("NO");
				return 0;
			}
			b[x[i]]-=(a[i]-b[i])*k[i];
			if (b[x[i]]>1e17)
			{
				printf("NO");
				return 0;
			}
		}
		else
		b[x[i]]+=b[i]-a[i];
	}
	printf((b[1]>=a[1])? "YES":"NO");
}