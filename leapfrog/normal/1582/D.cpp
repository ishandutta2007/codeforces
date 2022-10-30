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
const int N=100005;int n,a[N];
inline void exgcd(ll a,ll b,ll &x,ll &y) {b?exgcd(b,a%b,y,x),y-=a/b*x:x=y=1;}
inline void out(int x,int y) {int g=__gcd(x,y);printf("%d %d ",x/g,y/g);}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int g=0;for(int i=1;i<=n;i++) g=__gcd(g,a[i]);
	if(n&1)
	{
		for(int i=1;i<=n-3;i+=2) out(a[i+1],-a[i]);
		int x=a[n-2],y=a[n-1],z=a[n];
		if(x==z) printf("%d %d %d\n",-y,x+z,-y);
		else printf("%d %d %d\n",-y,x-z,y);
	}
	else
	{
		for(int i=1;i<=n;i+=2) out(a[i+1],-a[i]);
		putchar('\n');
	}
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}