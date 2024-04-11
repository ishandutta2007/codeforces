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
	//1 2 4 ... 2^w K K K K
	ll n,K,tot=1,res=0;read(n,K);
	while(tot<K&&tot<n) tot<<=1,res++;
	printf("%lld\n",res+(n-tot+K-1)/K);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}