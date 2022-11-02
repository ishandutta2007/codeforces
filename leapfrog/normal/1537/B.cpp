//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,a,b,x,y;
inline void solve()
{
	read(n),read(m),read(a),read(b);
	printf("%d %d %d %d\n",1,1,n,m);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}