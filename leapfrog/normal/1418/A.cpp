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
int Ca,x,y,k;
inline void solve()
{
	read(x),read(y),read(k);
	printf("%lld\n",(1ll*k*y+k+x-3)/(x-1)+k);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}