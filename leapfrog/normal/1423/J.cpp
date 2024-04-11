//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
const int P=1e9+7;
inline void solve()
{
	ll n,x,y;read(n),x=n/2%P,y=n/4%P;
	printf("%lld\n",((x+1)*(y+1)%P-(y+1)*y%P+P)%P);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}