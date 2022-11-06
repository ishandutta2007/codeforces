#include<cstdio>
#define int long long
const int N=1e5+5;
int n,p;
int a[N],sum[N];
signed main()
{
	int ans=0;
	register int i;
	scanf("%lld%lld",&n,&p);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(i=1;i<n;i++)
		if(sum[i]%p+(sum[n]-sum[i])%p>ans)
			ans=sum[i]%p+(sum[n]-sum[i])%p;
	printf("%lld\n",ans);
	return 0;
}