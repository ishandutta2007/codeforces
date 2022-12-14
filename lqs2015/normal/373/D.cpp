#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[77][77],sm[77][77],sum[77][77][77][77],x,y,xx,yy;
char str[77];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str);
		for (int j=1;j<=m;j++)
		{
			a[i][j]=str[j-1]-'0';
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			sm[i][j]=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+a[i][j];
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			{
				for (int h=k;h<=m;h++)
				{
					if (!(sm[j][h]-sm[i-1][h]-sm[j][k-1]+sm[i-1][k-1]))
					{
						sum[i][j][k][h]++;
					}
				}
			}
		}
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=m;k>=1;k--)
			{
				for (int h=k;h<=m;h++)
				{
					sum[i][j][k][h]=sum[i][j][k][h]+sum[i+1][j][k][h]+sum[i][j-1][k][h]+sum[i][j][k+1][h]+sum[i][j][k][h-1]-sum[i+1][j-1][k][h]-sum[i+1][j][k+1][h]-sum[i+1][j][k][h-1]-sum[i][j-1][k+1][h]-sum[i][j-1][k][h-1]-sum[i][j][k+1][h-1]+sum[i+1][j-1][k+1][h]+sum[i+1][j-1][k][h-1]+sum[i+1][j][k+1][h-1]+sum[i][j-1][k+1][h-1]-sum[i+1][j-1][k+1][h-1];
				}
			}
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		printf("%d\n",sum[x][xx][y][yy]);
	}
	return 0;
}