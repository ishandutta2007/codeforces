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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
inline void solve()
{
	int a,b,c,d,r=0;read(a,b,c,d);
	r+=abs(c-a),r+=abs(b-d);if(a^c&&b^d) r+=2;
	printf("%d\n",r);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}