#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
int T,n,l,r,a[N];ll s,ans;
ll slv1(int x)
{
	ll res=0;for(int i=1;i<=n;++i) a[i]+=x;
	if(a[1]>0) for(int i=2;i<=n;++i) res+=1ll*a[1]*a[i];
	else if(a[n]<0) for(int i=1;i<n;++i) res+=1ll*a[n]*a[i];
	else for(int i=1;i<n;++i)
		if(a[i]<0) res+=1ll*a[n]*a[i];else res+=1ll*a[1]*a[i];
	for(int i=1;i<=n;++i) a[i]-=x;return res-1ll*(n-1)*x*x;
}
void slv()
{
	scanf("%d",&n);l=-1e6,r=1e6;ans=-1e18;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);sort(a+1,a+n+1);
	s=0;for(int i=2;i<=n;++i) s+=a[1]+a[i];if(s>0) {puts("INF");return;}
	s=0;for(int i=1;i<n;++i) s+=a[n]+a[i];if(s<0) {puts("INF");return;}
	while(l+6<r)
	{
		int mid=(l+r)/2;ll tL=slv1(mid),tR=slv1(mid+1);
		ans=max(ans,max(tL,tR));
		if(tL<tR) l=mid+1;else r=mid;
	}for(int i=l;i<=r;++i) ans=max(ans,slv1(i));
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}