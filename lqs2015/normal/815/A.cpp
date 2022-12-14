#include<iostream>
#include<cstdio>
using namespace std;
int a[111][111],n,m,x,cnt,tim;
pair<int,int> ans[111111];
bool f;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	}
	x=1e9;
	for (int i=1;i<=m;i++)
	{
		x=min(x,a[1][i]);
	}
	for (int i=1;i<=m;i++)
	{
		tim=a[1][i]-x;
		for (int j=1;j<=tim;j++)
		{
			ans[++cnt]=make_pair(0,i);
			for (int k=1;k<=n;k++) 
			{
				if (!a[k][i])
				{
					printf("-1\n");
					return 0;
				}
				a[k][i]--;
			}
		}
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=2;j<=m;j++)
		{
			if (a[i][j]!=a[i][1]) 
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	if (n<=m)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=a[i][1];j++)
			{
				ans[++cnt]=make_pair(1,i);
			}
		}
	}
	else
	{
		x=1e9;
		for (int i=1;i<=n;i++) x=min(x,a[i][1]);
		for (int i=1;i<=x;i++)
		{
			for (int j=1;j<=m;j++)
			{
				ans[++cnt]=make_pair(0,j);
				for (int k=1;k<=n;k++) a[k][j]--;
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=a[i][1];j++)
			{
				ans[++cnt]=make_pair(1,i);
			}
		}
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		if (ans[i].first==1) printf("row %d\n",ans[i].second);
		else printf("col %d\n",ans[i].second);
	}
	return 0;
}