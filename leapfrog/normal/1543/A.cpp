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
ll n,m;
inline void solve()
{
	read(n),read(m);ll rs=abs(n-m);
	if(n==m) return puts("0 0"),void();
	printf("%lld %lld\n",rs,min(n%rs,rs-n%rs));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}