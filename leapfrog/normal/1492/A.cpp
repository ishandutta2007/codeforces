//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T;ll p,a,b,c;
inline void solve()
{
	read(p),read(a),read(b),read(c);
	ll res=2e18;
	res=min(res,(p+a-1)/a*a);
	res=min(res,(p+b-1)/b*b);
	res=min(res,(p+c-1)/c*c);
	printf("%lld\n",res-p);
}
int main() {for(read(T);T--;) solve();return 0;}
//int main() {return solve(),0;}