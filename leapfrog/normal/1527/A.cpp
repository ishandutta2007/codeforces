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
inline void solve() {int x;read(x);for(int i=1073741824;i;i>>=1) if(x&i) return printf("%d\n",i-1),void();}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}