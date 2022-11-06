#include<cstdio>
#define int long long
const int N=1e6+5;
int n;
int a[N];
inline void solve()
{
	int sum=0,cur;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum+=a[i];
	cur=(sum+n-2)/(n-1);
	for(i=1;i<=n;i++)
		if(cur<a[i])
			cur=a[i];
	printf("%lld\n",cur*(n-1)-sum);
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