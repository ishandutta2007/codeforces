#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,d,m,ans;
int a[N],sum[N];
signed main()
{
	int pos;
	register int i;
	scanf("%lld%lld%lld",&n,&d,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(i=1;;i++)
		if(i==n+1||a[i]>m)
			break;
	pos=i-1;
	for(i=pos;i>=0;i--)
		ans=max(ans,sum[pos]-sum[i]+sum[n]-sum[max(n-(n-pos+i+d)/(d+1),pos)]);
	printf("%lld\n",ans);
	return 0;
}