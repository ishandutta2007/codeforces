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
int T,n,k1,k2,c1,c2;char ch[500005];
inline void solve()
{
	read(n),read(k1),read(k2),read(c1),read(c2);
	int b=min(k1,k2)+abs(k2-k1)/2,c=min(n-k1,n-k2)+abs(k2-k1)/2;
	if(b>=c1&&c>=c2) puts("YES");else puts("NO");
}
int main() {for(read(T);T--;) solve();return 0;}