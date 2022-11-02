//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,K,a[100005];ll sm[100005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),sm[i]=sm[i-1]+a[i];
	ll res=0;for(int i=2;i<=n;i++) {ll nw=ceil(a[i]*100.0/K);res=max(res,nw-sm[i-1]);}
	printf("%lld\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}