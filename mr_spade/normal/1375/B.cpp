#include<cstdio>
const int N=1005;
int n,m;
int a[N][N];
inline void solve()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i][j]>(i>1)+(i<n)+(j>1)+(j<m))
				return puts("NO"),void();
	puts("YES");
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			printf("%d%c",(i>1)+(i<n)+(j>1)+(j<m),(j==m)?'\n':' ');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}