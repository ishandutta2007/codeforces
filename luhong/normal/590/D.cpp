#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[2][151][151*151],q[151];
int main()
{
	memset(dp,127,sizeof(dp));
	int n,m,s;scanf("%d%d%d",&n,&m,&s);
	s=min(s,n*n);
	for(int i=0;i<=n;i++)for(int j=0;j<=s;j++)dp[i&1][0][j]=0;
	for(int i=1;i<=n;i++)scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)
	{
		int ok=i&1;
		for(int j=1;j<=min(i,m);j++)
		{
			for(int k=0;k<=s;k++)
			{
				if(k-(i-j)>=0)dp[ok][j][k]=min(dp[ok^1][j][k],dp[ok^1][j-1][k-(i-j)]+q[i]);
				else dp[ok][j][k]=dp[ok^1][j][k];
			}
		}
	}
	int Min=1999999999;
	for(int i=0;i<=s;i++)Min=min(Min,dp[n&1][m][i]);
	printf("%d",Min);
	return 0;
}
//dp[i][j][k]ijk