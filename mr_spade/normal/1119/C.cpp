#include<cstdio>
const int N=505;
int n,m;
int a[N][N],b[N][N];
signed main()
{
	int cnt;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(i=1;i<=n;i++)
	{
		cnt=0;
		for(j=1;j<=m;j++)
			if(a[i][j]!=b[i][j])
				cnt++;
		if(cnt&1)
			return puts("No"),0;
		if(cnt&&i==n)
			return puts("No"),0;
		for(j=1;j<=m;j++)
			if(a[i][j]!=b[i][j])
				a[i][j]^=1,a[i+1][j]^=1;
	}
	puts("Yes");
	return 0;
}