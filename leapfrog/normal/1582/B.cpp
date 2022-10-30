//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
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
inline void solve()
{
	int n,c0=0,c1=0;read(n);
	for(int i=1,x;i<=n;i++) read(x),c0+=(x==0),c1+=(x==1);
	printf("%lld\n",(1ll*c1)<<c0);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}