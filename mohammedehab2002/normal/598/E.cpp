#include <iostream>
using namespace std;
int dp[35][35][55];
int main()
{
	
	for (int i=1;i<35;i++)
	{
		for (int x=1;x<35;x++)
		{
			for (int j=1;j<55;j++)
			{
				dp[i][x][j]=(1<<25);
				if (i*x<j)
				continue;
				if (i*x==j)
				dp[i][x][j]=0;
				else
				{
					for (int k=0;k<=j;k++)
					{
						for (int l=1;l<i;l++)
						dp[i][x][j]=min(dp[i][x][j],dp[l][x][k]+dp[i-l][x][j-k]+x*x);
						for (int l=1;l<x;l++)
						dp[i][x][j]=min(dp[i][x][j],dp[i][l][k]+dp[i][x-l][j-k]+i*i);
					}
				}
			}
		}
	}
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",dp[a][b][c]);
	}
}