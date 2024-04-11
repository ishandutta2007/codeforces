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
ll n,K;
inline void solve()
{
	read(n),read(K);ll rs=0;
	while(n) rs+=n%K+1,n/=K;
	printf("%lld\n",rs-1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}