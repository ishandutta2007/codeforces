#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;ll a[200005],K,g=0;
inline ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
inline void solve()
{
	read(n),read(K),g=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) g=gcd(g,a[i]-a[1]);
	if((K-a[1])%g) puts("NO");else puts("YES");
}
int main() {for(read(T);T--;) solve();return 0;}