#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[500005];
inline int abs(int a) {return a>0?a:-a;}
signed main()
{
	for(scanf("%lld",&t);t--;)
	{
		scanf("%lld",&n);long long ans=-1e16,s=1,s1=-1,s2=-1;
		for(int i=1;i<=n;i++) scanf("%lld",a+i),s1*=a[i];
		if(n==5) {printf("%lld\n",-s1);continue;}else s1=-1;
		sort(a+1,a+n+1);int lim=lower_bound(a+1,a+n+1,0)-a-1;
		{if(lim>=2) s1=a[1]*a[2];}{if(lim>=4) s2=a[3]*a[4];}
		if(lim==n) {printf("%lld\n",1ll*a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4]);continue;}
		for(int i=n;i>=lim;i--)
		{
			s*=a[i];
			if(i==n&&s1!=-1&&s2!=-1) ans=max(ans,s*s1*s2);
			if(i==n-2&&s1!=-1) ans=max(ans,s*s1);
			if(i==n-4) ans=max(ans,s);
		}
		printf("%lld\n",ans);
	}
	return 0;
}