//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;const int P=1e9+7;
int n,K;
inline void solve()
{
	read(n),read(K);int rs=1;
	for(int i=1;i<=K;i++) rs=1ll*rs*n%P;
	printf("%d\n",rs);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}