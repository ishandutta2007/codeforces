#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,t;
double p;
double dp[N+5][N+5];
int main()
{
	scanf("%d%lf%d",&n,&p,&t);
	for(int i=1;i<=n;i++) for(int j=1;j<=t;j++) dp[i][j]=0;
	dp[0][0]=1;
	for(int i=1;i<=t;i++) dp[0][i]=dp[0][i-1]*(1-p);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=t;j++)
		{
			dp[i][j]=dp[i-1][j-1]*p+dp[i][j-1]*(1-p);
		}
	}
	for(int j=1;j<=t;j++) 
	{
		dp[n][j]=dp[n-1][j-1]*p+dp[n][j-1];
	}
	double ans=0;
	for(int i=1;i<=n;i++) ans+=(dp[i][t]*(double)i);
	printf("%.30lf\n",ans);
	return 0;
}