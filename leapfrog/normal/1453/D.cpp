//Coded by Kamiyama_Shiki on 2021.10.31 {{{
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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int rs[2005],rst;
inline void add(int x) {rs[++rst]=1;while(--x) rs[++rst]=0;}
inline void solve()
{
	ll K;read(K);if(K&1) return puts("-1"),void();else rst=0,K>>=1;
	for(int i=60;K;) {while((1ll<<i)-1>K) i--;add(i),K-=(1ll<<i)-1;}
	printf("%d\n",rst);for(int i=1;i<=rst;i++) printf("%d%c",rs[i],i==rst?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}