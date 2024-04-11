//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,a[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	ll sm=0,rs=1e18;int mn1=1e9,mn2=1e9,nw1=n,nw2=n;
	for(int i=1;i<=n;i++)
	{
		if(i&1) mn1=min(mn1,a[i]),nw1--;else mn2=min(mn2,a[i]),nw2--;
		sm+=a[i],rs=min(rs,sm+1ll*nw1*mn1+1ll*nw2*mn2);
	}
	printf("%lld\n",rs);
}
int main() {for(read(T);T--;) solve();return 0;}