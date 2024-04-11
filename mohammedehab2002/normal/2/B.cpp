#include <iostream>
#include <string.h>
using namespace std;
pair<int,char> dp[1005][1005][2];
int arr[1005][1005],f[]={2,5};
int fact(int a,int b)
{
	if (!a)
	return 1;
	int ans=0;
	while (a%f[b]==0)
	{
		ans++;
		a/=f[b];
	}
	return ans;
}
void go(int i,int x,int a)
{
	if (dp[i][x][a].second=='E')
	return;
	if (dp[i][x][a].second=='D')
	go(i-1,x,a);
	else
	go(i,x-1,a);
	printf("%c",dp[i][x][a].second);
}
int main()
{
	int n,zx=-1;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			scanf("%d",&arr[i][x]);
			if (!arr[i][x])
			zx=i;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<n;x++)
		{
			for (int j=0;j<2;j++)
			{
				if (!i && !x)
				dp[i][x][j]=make_pair(fact(arr[i][x],j),'E');
				else if (!i)
				dp[i][x][j]=make_pair(fact(arr[i][x],j)+dp[i][x-1][j].first,'R');
				else if (!x)
				dp[i][x][j]=make_pair(fact(arr[i][x],j)+dp[i-1][x][j].first,'D');
				else
				{
					if (dp[i-1][x][j].first<dp[i][x-1][j].first)
					dp[i][x][j]=make_pair(fact(arr[i][x],j)+dp[i-1][x][j].first,'D');
					else
					dp[i][x][j]=make_pair(fact(arr[i][x],j)+dp[i][x-1][j].first,'R');
				}
			}
		}
	}
	int ans=1;
	if (dp[n-1][n-1][0].first<dp[n-1][n-1][1].first)
	ans=0;
	if (zx!=-1 && dp[n-1][n-1][ans].first>1)
	{
		printf("%d\n",1);
		for (int i=0;i<zx;i++)
		printf("D");
		for (int i=1;i<n;i++)
		printf("R");
		for (int i=1;i<n-zx;i++)
		printf("D");
		return 0;
	}
	printf("%d\n",dp[n-1][n-1][ans].first);
	go(n-1,n-1,ans);
}