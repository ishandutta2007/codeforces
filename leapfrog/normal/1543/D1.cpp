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
int n,K;
inline int ask(int x) {cout<<x<<endl;int y;read(y);return y;}
inline void solve()
{
	read(n),read(K);if(ask(0)) return;
	for(int i=1;i<n;i++) if(ask((i-1)^i)) return;
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}