//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=500005;
int n,a[500005],K;
int main()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	ll sm=0;for(int i=1;i<=n;i++) sm+=a[i];
	int l=1,r=sm/n,mn=1,mx=0;
	while(l<=r)
	{
		int md=(l+r)>>1;ll jd=0;
		for(int i=1;i<=n;i++) if(a[i]<=md) jd+=md-a[i];
		if(jd<=K) mn=md,l=md+1;else r=md-1;
	}
	l=(sm+n-1)/n,r=0;for(int i=1;i<=n;i++) r=mx=max(mx,a[i]);
	while(l<=r)
	{
		int md=(l+r)>>1;ll jd=0;
		for(int i=1;i<=n;i++) if(a[i]>=md) jd+=a[i]-md;
		if(jd<=K) mx=md,r=md-1;else l=md+1;
	}
	return printf("%d\n",mx-mn),0;
}