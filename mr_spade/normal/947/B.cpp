#include<cstdio>
#include<algorithm>
using std::upper_bound;
#define int long long
const int N=1e5+5;
int n;
int v[N],t[N],sum[N];
int d[N],res[N];
signed main()
{
	int pos;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&v[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&t[i]);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+t[i];
	for(i=1;i<=n;i++)
	{
		pos=upper_bound(sum+1,sum+n+1,v[i]+sum[i-1])-sum;
		d[i]++;d[pos]--;
		res[pos]+=v[i]+sum[i-1]-sum[pos-1];
	}
	for(i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		res[i]+=t[i]*d[i];
	}
	for(i=1;i<=n;i++)
		printf("%lld ",res[i]);
	putchar('\n');
	return 0;
}