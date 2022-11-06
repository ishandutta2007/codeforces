#include<cstdio>
#include<algorithm>
#define int long long
using std::max;
const int N=1e5+5;
int n;
int a[N],b[N];
inline void solve()
{
	int t=0;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=2;i<=n;i++)
		b[i]=max(0ll,b[i-1]+a[i-1]-a[i]),t=max(t,b[i]);
	if(t<=0)
		puts("0");
	else
		printf("%lld\n",(int)(log2(t+1e-5))+1);
	return;
}
signed main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}