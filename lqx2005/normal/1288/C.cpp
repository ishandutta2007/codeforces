#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int maxm=40;
const int mod=1e9+7;
int n,m;
int dp[maxm+5][maxn+5];
void add(int &x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	dp[0][1]=1;
	for(int i=1;i<=m*2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=j;k++)
			{
				add(dp[i][j],dp[i-1][k]);
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++) add(sum,dp[m*2][i]);
	printf("%d\n",sum);
	return 0;
}