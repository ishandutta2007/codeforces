//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
inline void solve()
{
	int n;read(n);if(n==1) return puts("z"),void();
	int x=n/2;for(int i=1;i<x;i++) putchar('z');
	putchar('y');if(n&1) putchar('x');
	for(int i=1;i<=x;i++) putchar('z');
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}