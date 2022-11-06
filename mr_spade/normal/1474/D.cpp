#include<cstdio>
#include<algorithm>
#define int long long
const int N=4e5+5;
int n;
int a[N],b[N],bmn[N],bmn2[N];
inline void solve()
{
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		b[i]=a[i]-b[i-1];
	bmn[n+1]=bmn[n+2]=0x3f3f3f3f3f3f3f3f;
	for(i=n;i>=1;i--)
		bmn[i]=std::min(b[i],bmn[i+2]);
	bmn2[0]=0x3f3f3f3f3f3f3f3f;
	for(i=1;i<=n;i++)
		bmn2[i]=std::min(bmn2[i-1],b[i]);
	if(bmn[1]>=0&&bmn[2]>=0&&b[n]==0)
		return puts("YES"),void();
	for(i=1;i<=n-1;i++)
		if((n-i)&1)
		{
			if(bmn2[i-1]>=0&&b[n]+2*(a[i]-a[i+1])==0&&bmn[i+1]+2*(a[i]-a[i+1])>=0&&bmn[i+2]-2*(a[i]-a[i+1])>=0&&b[i]-a[i]+a[i+1]>=0)
				return puts("YES"),void();
		}
		else
		{
			if(bmn2[i-1]>=0&&b[n]-2*(a[i]-a[i+1])==0&&bmn[i+1]+2*(a[i]-a[i+1])>=0&&bmn[i+2]-2*(a[i]-a[i+1])>=0&&b[i]-a[i]+a[i+1]>=0)
				return puts("YES"),void();
		}
	puts("NO");
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