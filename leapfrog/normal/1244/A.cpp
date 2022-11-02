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
int a,b,c,d,k;
inline void solve()
{
	read(a),read(b),read(c),read(d),read(k);
	a=(a+c-1)/c,b=(b+d-1)/d;if(a+b>k) puts("-1");else printf("%d %d\n",a,k-a);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}