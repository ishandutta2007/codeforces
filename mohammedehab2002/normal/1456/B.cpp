#include <bits/stdc++.h>
using namespace std;
#define msb __builtin_clz
int a[100005],cum[100005];
int main()
{
	int n,ans=1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cum[i]=(a[i]^cum[i-1]);
	}
	for (int i=1;i<n-1;i++)
	{
		if (msb(a[i])==msb(a[i+1]) && msb(a[i+1])==msb(a[i+2]))
		{
			printf("1");
			return 0;
		}
	}
	for (int i=1;i<n-1;i++)
	{
		for (int j=i+2;j<=n;j++)
		{
			for (int m=i;m<j;m++)
			{
				if ((cum[m]^cum[i-1])>(cum[j]^cum[m]))
				ans=min(ans,j-i-1);
			}
		}
	}
	if (ans==1e9)
	ans=-1;
	printf("%d",ans);
}