#include<cstdio>
const int N=3e5+5,M=2e6+5;
int n;
long long ans;
int a[N];
int cnt[2][M];
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]^=a[i-1];
	cnt[0][0]++;
	for(i=1;i<=n;i++)
		ans+=cnt[i&1][a[i]],cnt[i&1][a[i]]++;
	printf("%lld\n",ans);
	return 0;
}