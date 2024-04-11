#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define ll long long
int T,n;ll ans,mn,a[N],b[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld %lld",&a[i],&b[i]);a[0]=a[n];b[0]=b[n];
		for(int i=1;i<=n;++i) {ll t=min(a[i],b[i-1]);ans+=a[i]-t;a[i]=t;}
		mn=a[1];for(int i=2;i<=n;++i) mn=min(mn,a[i]);printf("%lld\n",ans+mn);
	}return 0;
}