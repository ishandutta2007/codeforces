//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
ll n;
inline void solve()
{
	read(n);if(n%2050) return puts("-1"),void();else n/=2050;
	int cnt=0;while(n) cnt+=n%10,n/=10;
	printf("%d\n",cnt);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}