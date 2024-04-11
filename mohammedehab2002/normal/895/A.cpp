#include <iostream>
#include <math.h>
using namespace std;
int arr[365];
int main()
{
	int n,ans=360;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=n;x++)
		{
			int sum=0;
			for (int j=i;j!=x;j=j%n+1)
			sum+=arr[j];
			ans=min(ans,abs(180-sum)*2);
		}
	}
	printf("%d",ans);
}