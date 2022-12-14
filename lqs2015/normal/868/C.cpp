#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,k,p;
bool a[20],r[111111][7],f;
void dfs(int i,int p)
{
	if (i==k)
	{
		if (a[p])
		{
			printf("YES\n");
			exit(0);
		}
		return;
	}
	if (p&(1<<i)) dfs(i+1,p);
	else
	{
		dfs(i+1,p);
		dfs(i+1,p+(1<<i));
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		p=0;f=0;
		for (int j=0;j<k;j++) 
		{
			scanf("%d",&r[i][j]);
			if (!r[i][j]) p+=pow(2,j);
			else f=1;
		}
		if (!f) 
		{
			printf("YES\n");
			return 0;
		}
		a[p]=1;
	}
	for (int i=1;i<=n;i++)
	{
		p=0;
		for (int j=0;j<k;j++)
		{
			if (r[i][j]) p+=pow(2,j);
		}
		dfs(0,p);
	}
	printf("NO\n");
	return 0;
}