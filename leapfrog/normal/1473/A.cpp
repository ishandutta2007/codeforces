//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,n,d;
inline void solve()
{
	read(n),read(d);int mn=1e9,se=1e9,mx=0;
	for(int i=1,x;i<=n;i++) {read(x),mx=max(mx,x);if(x<mn) se=mn,mn=x;else if(x<se) se=x;}
	if(mn+se>d&&mx>d) puts("NO");else puts("YES");
}
int main() {for(read(T);T--;) solve();return 0;}