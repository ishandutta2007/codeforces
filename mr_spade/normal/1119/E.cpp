#include<cstdio>
#include<algorithm>
#define int long long
using std::min;
const int N=3e5+5;
int n,ans;
int a[N];
signed main()
{
	int last=0,cur;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		cur=min(last,a[i]/2);
		ans+=cur;last-=cur;a[i]-=cur*2;
		cur=a[i]/3;
		ans+=cur;a[i]-=cur*3;
		last+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}