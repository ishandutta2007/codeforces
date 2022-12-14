#include<iostream>
#include<cstdio>
using namespace std;
int ans[111][111],n,m,b[111],a[111],curr,curc,cur;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) curr^=a[i];
	for (int i=1;i<=m;i++) curc^=b[i];
	if (curr!=curc)
	{
		printf("NO\n");
		return 0;
	}
	for (int i=0;i<=30;i++)
	{
		cur=0;
		for (int j=1;j<m;j++)
		{
			if (b[j]&(1<<i))
			{
				ans[1][j]+=(1<<i);
				cur^=1;
			}
		}
		if (a[1]&(1<<i) && !cur) ans[1][m]+=(1<<i);
		else if (!(a[1]&(1<<i)) && cur) ans[1][m]+=(1<<i);
		for (int j=2;j<=n;j++)
		{
			if (a[j]&(1<<i)) ans[j][m]+=(1<<i);
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}