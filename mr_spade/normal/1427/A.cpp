#include<cstdio>
#include<algorithm>
using std::sort;
using std::reverse;
const int N=1045;
int n,a[N];
inline void solve()
{
	int sum=0;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if((sum+=a[i])==0)
			goto end;
	puts("YES");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	return;
	end:;
	reverse(a+1,a+n+1);
	for(i=1;i<=n;i++)
		if((sum+=a[i])==0)
			return puts("NO"),void();
	puts("YES");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
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