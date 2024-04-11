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
int Ca,n,a[100005];ll sm[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sm[n+1]=0;for(int i=n;i;i--) sm[i]=a[i]+sm[i+1];
	ll rs=-1e18;for(int i=1;i<=n;i++) rs=max(rs,sm[i]);
	printf("%lld\n",rs);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}