//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n,c,a[200005],b[200005];
inline void solve()
{
	read(n),read(c);for(int i=1;i<=n;i++) read(a[i]);
	b[n]=0;for(int i=1;i<n;i++) read(b[i]);
	ll rs=1e18,nw=0,ls=0;for(int i=1;i<=n;i++)
	{
		rs=min(rs,nw+max(0ll,c-ls+a[i]-1)/a[i]);
		ll qwq=max(0ll,b[i]-ls+a[i]-1)/a[i];
		nw+=qwq+1,ls+=a[i]*qwq-b[i];
	}
	printf("%lld\n",rs);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}