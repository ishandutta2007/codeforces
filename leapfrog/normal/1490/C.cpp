//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
ll n;int T;
inline void solve()
{
	read(n);
	for(int i=1;1ll*i*i*i*2<=n;i++)
	{
		ll qwq=n-1ll*i*i*i;int gg=pow(qwq,1.0/3);
		if(1ll*gg*gg*gg==qwq) return puts("YES"),void();else gg--;
		if(1ll*gg*gg*gg==qwq) return puts("YES"),void();else ++++gg;
		if(1ll*gg*gg*gg==qwq) return puts("YES"),void();
	}
	puts("NO");
}
int main() {for(read(T);T--;) solve();return 0;}