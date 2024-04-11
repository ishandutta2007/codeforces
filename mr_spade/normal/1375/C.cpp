#include<cstdio>
#include<algorithm>
using std::max;
const int N=3e5+5;
int n;
int a[N];
inline void solve()
{
	int mx=0;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	puts(a[1]>a[n]?"NO":"YES");
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