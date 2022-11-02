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
	int n,m,K;read(n,m,K),K-=2;
	if(m<n-1||K<0||m>1ll*n*(n-1)/2) return puts("NO"),void();
	if(n==1) return puts("YES"),void();
	if(K==0) return puts("NO"),void();
	if(m==1ll*n*(n-1)/2) return puts("YES"),void();
	puts(K<=1?"NO":"YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}