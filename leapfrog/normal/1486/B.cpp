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
int T,n,x[100005],y[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(x[i]),read(y[i]);
	sort(x+1,x+n+1),sort(y+1,y+n+1);if(n&1) return puts("1"),void();
	ll res=1ll*(x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1);printf("%lld\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}