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
int n,m,K,a[2000005],b[2000005];char ch[2000005];ll N,M;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	ll rs=0;for(int i=1;i<n;i++) rs=max(rs,1ll*a[i]*a[i+1]);
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}