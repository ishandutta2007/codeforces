#include <iostream>
using namespace std;
int arr[300005],l[20],dp[20][300005];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	for (int i=0;i<20;i++)
	l[i]=n+1;
	for (int i=n;i>0;i--)
	{
		for (int j=0;j<20;j++)
		dp[j][i]=n+1;
		for (int j=0;j<20;j++)
		{
			if (arr[i]&(1<<j))
			{
				dp[j][i]=i;
				if (l[j]!=n+1)
				{
					for (int k=0;k<20;k++)
					dp[k][i]=min(dp[k][i],dp[k][l[j]]);
				}
				l[j]=i;
			}
		}
	}
	while (q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		bool ok=0;
		for (int i=0;i<20;i++)
		{
			if ((arr[b]&(1<<i)) && dp[i][a]<=b)
			ok=1;
		}
		if (ok)
		puts("Shi");
		else
		puts("Fou");
	}
}