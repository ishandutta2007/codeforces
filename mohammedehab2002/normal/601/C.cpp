#include <bits/stdc++.h>
using namespace std;
int a[1005];
double dp[100005],cum[100005];
int main()
{
	int n,m,s=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	dp[0]=1;
	for (int i=0;i<s;i++)
	cum[i]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=s-1;j>=0;j--)
		{
			if (j<i)
			{
				dp[j]=0;
				continue;
			}
			dp[j]=cum[j-1];
			if (j>m)
			dp[j]-=cum[j-m-1];
			if (j>=a[i])
			dp[j]-=dp[j-a[i]];
			dp[j]/=(m-1);
		}
		cum[0]=0;
		for (int j=1;j<s;j++)
		cum[j]=cum[j-1]+dp[j];
	}
	double p=0;
	for (int i=0;i<s;i++)
	p+=dp[i];
	printf("%.9lf",1+p*(m-1));
}