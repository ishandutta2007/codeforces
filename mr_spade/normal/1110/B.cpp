#include<cstdio>
#include<algorithm>
#define int long long
using std::sort;
const int N=1e5+5;
int n,k;
int b[N],a[N];
signed main()
{
	int ans=0;
	register int i;
	scanf("%lld%*d%lld",&n,&k);k=n-k;
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(i=1;i<n;i++)
		a[i]=b[i+1]-b[i]-1;
	sort(a+1,a+n);
	for(i=1;i<=k;i++)
		ans+=a[i];
	printf("%lld\n",ans+n);
	return 0;
}