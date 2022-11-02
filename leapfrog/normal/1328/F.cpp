//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
const int N=200005;int n,K,a[N],cnt[N];ll qz[N],hz[N];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=n;i;i--) hz[i]=hz[i+1]+a[i];
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	for(int i=1;i<=n;i++) qz[i]=1ll*a[i]*i-qz[i];
	for(int i=n;i;i--) hz[i]=hz[i]-1ll*a[i]*(n-i+1);
	for(int i=1;i<=n;i++) cnt[i]=(a[i]==a[i-1])*cnt[i-1]+1;
	ll res=1e18;for(int i=1;i<=n;i++) if(cnt[i]>=K) return puts("0"),0;
	//for(int i=1;i<=n;i++) printf("%lld %lld %d\n",qz[i],hz[i],cnt[i]);
	for(int i=1;i<=n;i++)
	{
		if(i<K) res=min(res,qz[i]+hz[i]-n+K);else res=min(res,qz[i]-i+K);
		if(i>n-K+1) res=min(res,qz[i]+hz[i]-n+K);else res=min(res,hz[i]-n+i+K-1);
	}
	return printf("%lld\n",res),0;
}