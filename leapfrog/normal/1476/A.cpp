//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,K;
inline void solve()
{
	read(n),read(K);int x=(n+K-1)/K;
	ll sm=1ll*x*K;printf("%lld\n",sm/n+!!(sm%n));
}
int main() {for(read(T);T--;) solve();return 0;}