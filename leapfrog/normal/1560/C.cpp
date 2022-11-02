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
	int x,v;read(x),v=sqrt(x);
	if(1ll*v*v==x) return printf("%d 1\n",v),void();
	int ls=x-v*v;if(ls>v+1) printf("%d %d\n",v+1,v-ls+v+2);
	else printf("%d %d\n",ls,v+1);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}