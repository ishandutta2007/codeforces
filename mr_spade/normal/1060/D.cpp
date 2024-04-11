#include<cstdio>
#include<algorithm>
#define abs(x) ((x)<0?-(x):(x))
#define int long long
using std::min;
using std::sort;
const int N=1e5+5;
int n,ans;
int a[N],b[N];
signed main()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]),ans+=a[i]+b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
		ans-=min(a[i],b[i]);
	printf("%lld\n",ans+n);
	return 0;
}