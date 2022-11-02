//Coded by Kamiyama_Shiki on 2021.11.12 {{{
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
	ll n,rs=0;read(n);
	if(n<=10)
	{
		for(ll i=1;i<=n;i++) rs=max(rs,min(i*(i-1)/2,n-i)+n-i);
		printf("%lld\n",rs);return;
	}
	ll x=(-1+sqrt(1+8*n))/2;
	printf("%lld\n",max(min(x*(x-1)/2,n-x)+n-x,min(x*(x+1)/2,n-x-1)+n-x-1));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}