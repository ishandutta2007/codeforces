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
inline void solve()
{
	int a,b,c,x,y;read(a),read(b),read(c),read(x),read(y),a>>=1;
	if(x>y) printf("%d\n",x*min(a,b)+y*min(max(a-b,0),c));
	else printf("%d\n",y*min(a,c)+x*min(max(a-c,0),b));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}