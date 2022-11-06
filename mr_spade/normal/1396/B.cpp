#include<cstdio>
#include<algorithm>
using std::max;
int n,sum,Max;
inline void solve()
{
	int a;
	register int i;
	sum=Max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a),sum+=a,Max=max(Max,a);
	if((sum&1)||Max>(sum>>1))
		puts("T");
	else
		puts("HL");
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