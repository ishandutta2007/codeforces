#include <bits/stdc++.h>
using namespace std;
const int maxn=2000;
const int mod=998244353;
int dp[maxn+5][maxn+5][4];
int n,k;
void add(int &x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	dp[1][1][0]=1;
	dp[1][2][1]=1;
	dp[1][2][2]=1;
	dp[1][1][3]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			add(dp[i+1][j][0],dp[i][j][0]);
			add(dp[i+1][j+1][1],dp[i][j][0]);
			add(dp[i+1][j+1][2],dp[i][j][0]);
			add(dp[i+1][j+1][3],dp[i][j][0]);//0
			add(dp[i+1][j][0],dp[i][j][1]);
			add(dp[i+1][j][1],dp[i][j][1]);
			add(dp[i+1][j+2][2],dp[i][j][1]);
			add(dp[i+1][j][3],dp[i][j][1]);//1
			add(dp[i+1][j][0],dp[i][j][2]);
			add(dp[i+1][j+2][1],dp[i][j][2]);
			add(dp[i+1][j][2],dp[i][j][2]);
			add(dp[i+1][j][3],dp[i][j][2]);//2
			add(dp[i+1][j+1][0],dp[i][j][3]);
			add(dp[i+1][j+1][1],dp[i][j][3]);
			add(dp[i+1][j+1][2],dp[i][j][3]);
			add(dp[i+1][j][3],dp[i][j][3]);//3
		}
	}
	int sum=0;
	add(sum,dp[n][k][0]);
	add(sum,dp[n][k][1]);
	add(sum,dp[n][k][2]);
	add(sum,dp[n][k][3]);
	printf("%d\n",sum);
	return 0;
}