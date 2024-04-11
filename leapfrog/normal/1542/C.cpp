//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const int P=1e9+7;
inline void solve()
{
	ll n,nw=1;read(n);int rs=n%P;
	for(int i=2;nw<=n;i++) rs=(rs+(n/nw)%P)%P,nw=nw/__gcd(nw,1ll*i)*i;
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}