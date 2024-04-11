#include <iostream>
#include <string.h>
using namespace std;
long double dp[10005][1005];
int main()
{
	int k,q;
	scanf("%d%d",&k,&q);
	long double dk=k;
	dp[1][1]=1;
	for (int i=2;i<=10000;i++)
	{
		for (int c=1;c<=k;c++)
		dp[i][c]=((long double)c/dk)*dp[i-1][c]+((long double)(dk-c+1)/k)*dp[i-1][c-1];
	}
	while (q--)
	{
		int a;
		scanf("%d",&a);
		for (int i=1;i<=10000;i++)
		{
			if (dp[i][k]>=(long double)a/2000.0)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}