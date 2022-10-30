//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}
template<typename T,typename...L>
inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
inline void solve()
{
	int a,b,K,g;read(a,b,K),g=__gcd(a,b),a/=g,b/=g;
	a>b?swap(a,b),0:0;int v=(b-2)/a+1;
	if(v>=K) puts("REBEL");else puts("OBEY");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}