#include<cstdio>
#define int long long
const int N=1e5+5;
int n,ans;
int a[N],b[N];
signed main()
{
	int last=0;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=n;i>=1;i--)
	{
		last--;
		if(a[i]+1>last)
			last=a[i]+1;
		b[i]=last;
	}
	for(i=2;i<=n;i++)
		if(b[i-1]>b[i])
			b[i]=b[i-1];
	for(i=1;i<=n;i++)
		ans+=b[i]-a[i]-1;
	printf("%lld\n",ans);
	return 0;
}