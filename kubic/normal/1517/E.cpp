#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 998244353
#define ll long long
int T,n,ans,a[N];ll pr[N],sf[N],pr1[N];
void slv()
{
	scanf("%d",&n);ans=sf[n+1]=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) pr[i]=pr[i-1]+a[i];
	for(int i=n;i;--i) sf[i]=sf[i+1]+a[i];pr1[1]=a[1];
	for(int i=2;i<=n;++i) pr1[i]=pr1[i-2]+a[i];
	if(n<4)
	{
		for(int i=0;i<1<<n;++i)
		{
			ll s=0;for(int j=1;j<=n;++j) if(i>>j-1&1) s+=a[j];
			if(s*2<pr[n]) ++ans;
		}printf("%d\n",ans);return;
	}for(int i=n+1;i;--i) if(sf[i]*2<pr[n]) ++ans;
	for(int i=1;i<n;i+=2) if(pr1[i]*2<pr[n]) ++ans;
	for(int i=1;i<n-1;i+=2) if((pr1[i]+a[n])*2<pr[n]) ++ans;
	for(int i=2,t=n&1?n-2:n-1;i<n;i+=2)
	{
		while(t>0 && (pr1[t]+pr1[i])*2>=pr[n]) t-=2;
		if(t>0) ans=(ans+t/2+1)%MOD;
	}
	for(int i=2,t=n&1?n-2:n-1;i<n;i+=2)
	{
		while(t>0 && (pr1[t]+pr1[i]-a[1])*2>=pr[n]) t-=2;
		if(t>0) ans=(ans+t/2+1)%MOD;
	}
	for(int i=2,t=n&1?n-2:n-3;i<n-1;i+=2)
	{
		while(t>0 && (pr1[t]+pr1[i]+a[n])*2>=pr[n]) t-=2;
		if(t>0) ans=(ans+t/2+1)%MOD;
	}
	for(int i=2,t=n&1?n-2:n-3;i<n-1;i+=2)
	{
		while(t>0 && (pr1[t]+pr1[i]-a[1]+a[n])*2>=pr[n]) t-=2;
		if(t>0) ans=(ans+t/2+1)%MOD;
	}printf("%d\n",ans%MOD);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}