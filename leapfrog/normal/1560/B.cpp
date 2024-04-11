#include<bits/stdc++.h>//{{{
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
	int a,b,c;read(a,b,c);
	if(abs(a-b)*2<max(a,b)||abs(a-b)*2<c) return puts("-1"),void();
	if(abs(a-b)+c>abs(a-b)*2) printf("%d\n",c-abs(a-b));else printf("%d\n",c+abs(a-b));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}