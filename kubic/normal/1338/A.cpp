#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
int T,n,x,ans,a[N];
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		x=ans=0;scanf("%lld",&n);for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=2,t;i<=n;++i) if(a[i]<a[i-1]) t=a[i-1]-a[i],x|=t,a[i]=a[i-1];
		for(int i=0;i<=40;++i) if(x&(1ll<<i)) ans=i+1;printf("%lld\n",ans);
	}return 0;
}