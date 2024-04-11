#include<cstdio>
#include<algorithm>
#define int long long
using std::min;
using std::max;
using std::min;
const int N=105;
int k;
int a[N],p[N],s[N];
inline void solve()
{
	int t,ans=0x3f3f3f3f3f3f3f3f;
	register int i,j;
	scanf("%lld",&k);
	for(i=1;i<=7;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=7;i++)
		p[i]=p[i-1]+a[i];
	for(i=7;i>=1;i--)
		s[i]=s[i+1]+a[i];
	for(i=1;i<=7;i++)
		for(j=i;j<=7;j++)
			if(p[j]-p[i-1]>=k)
				ans=min(ans,j-i+1);
	for(i=1;i<=7;i++)
		for(j=1;j<=7;j++)
		{
			t=max(0ll,(k-s[i]-p[j]+p[7]-1)/p[7]);
			if(t*7+(7-i+1)+j<ans)
				ans=t*7+(7-i+1)+j;
		}
	printf("%lld\n",ans);
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