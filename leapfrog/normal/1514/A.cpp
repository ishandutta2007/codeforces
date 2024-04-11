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
int n,m,K,a[1000005];
inline char chk(int x) {int w=sqrt(x);return w*w==x||(w+1)*(w+1)==x||(w-1)*(w-1)==x;}
inline void solve()
{
	read(n);char fg=0;
	for(int i=1,x;i<=n;i++) read(x),fg|=!chk(x);
	puts(fg?"YES":"NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}