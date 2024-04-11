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
int Ca,n;ll sm=0,mx=0,rs=0;
inline void solve()
{
	read(n),sm=0,mx=0;for(int i=1,x;i<=n;i++) read(x),sm+=x,mx=max(mx,sm);
	read(n),rs+=mx,sm=mx=0;for(int i=1,x;i<=n;i++) read(x),sm+=x,mx=max(mx,sm);
	printf("%lld\n",rs+mx),rs=0;
}
int main() {for(read(Ca);Ca--;) solve();return 0;}