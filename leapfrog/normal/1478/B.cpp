//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,Q,d,x;
inline void solve() {read(x);if(x>=10*d) puts("YES");else {for(;x>=d;x-=d) if(x%10==d) return puts("YES"),void();puts("NO");}}
int main() {for(read(T);T--;) for(read(Q),read(d);Q--;) solve();return 0;}