#include<cstdio>
#include<cstring>
const int N=105;
int n,m;
int a[N][N],w[N<<1];
inline void solve()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	memset(w,0,sizeof(w));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]),w[i+j]^=a[i][j];
	for(i=0;i<=n+m;i++)
		if(w[i])
			return puts("Ashish"),void();
	puts("Jeel");
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