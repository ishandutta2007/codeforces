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
int Ca,n,m,a[1000005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	if(a[1]!=a[2]&&a[1]!=a[3]) return puts("1"),void();
	for(int i=2;i<=n;i++) if(a[i]!=a[1]) return printf("%d\n",i),void();
}
int main() {for(read(Ca);Ca--;) solve();return 0;}