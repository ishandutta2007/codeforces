//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,m;ll X;
inline void solve()
{
	read(n),read(m),read(X);int a=(X+n-1)/n,b=(X-1)%n+1;
	printf("%lld\n",1ll*(b-1)*m+a);
}
int main() {for(read(T);T--;) solve();return 0;}