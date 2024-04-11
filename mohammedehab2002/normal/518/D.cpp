#include <iostream>
using namespace std;
double dp[2005][2005];
int main()
{
	int n,t;
	double p;
	scanf("%d%lf%d",&n,&p,&t);
	for (int i=1;i<=n;i++)
	{
		for (int x=1;x<=t;x++)
		dp[i][x]=dp[i][x-1]*(1-p)+(dp[i-1][x-1]+1)*p;
	}
	printf("%.9lf",dp[n][t]);
}