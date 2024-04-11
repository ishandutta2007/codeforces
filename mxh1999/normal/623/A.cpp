#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
int a[510][510];
int ans[510];
bool ok(int x,int y)
{
	if (ans[x]==ans[y])	return true;
	if (abs(ans[x]-ans[y])==1)	return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=true;
		a[y][x]=true;
	}
	for (int i=1;i<=n;i++)	a[i][i]=1;
	int xx=0,yy=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[i][j]==0)	{xx=i,yy=j;break;}
	for (int i=1;i<=n;i++)	ans[i]=2;
	ans[xx]=1;ans[yy]=3;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[i][j]==0)
		{
			if (a[i][xx]==1)	ans[i]=1;else ans[i]=3;
			if (a[j][xx]==1)	ans[j]=1;else ans[j]=3;
		}
	bool bo=true;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (ok(i,j)!=a[i][j])
		{
			bo=false;break;
		}
	if (!bo)	printf("No\n");else
	{
		printf("Yes\n");
		for (int i=1;i<=n;i++)	printf("%c",ans[i]+'a'-1);
		printf("\n");
	}
	return 0;
}