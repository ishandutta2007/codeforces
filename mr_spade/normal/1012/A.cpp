#include<cstdio>
#include<algorithm>
#define int long long
using std::sort;
const int N=1e6+5;
int n,ans;
int a[N];
signed main()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n*2+1);
	ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
	for(i=2;i+n-1<n*2;i++)
		if((a[i+n-1]-a[i])*(a[n*2]-a[1])<ans)
			ans=(a[i+n-1]-a[i])*(a[n*2]-a[1]);
	printf("%lld\n",ans);
	return 0;
}