#include<cstdio>
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=1e6+5;
int n;
int a[N];
inline void solve()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		printf("%d ",(i&1)?abs(a[i]):-abs(a[i]));
	putchar('\n');
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