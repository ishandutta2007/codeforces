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
int T,n,a[100005],b[100005],c[100005];
inline void solve()
{
	read(n);ll nw=0,res=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=n;i++) read(c[i]);
	for(int i=n;i>1;i--)
	{
		if(!nw) nw=a[i]-1;
		if(c[i]==b[i]) {res=max(res,nw+2),nw=0;continue;}
		++++nw,res=max(res,nw+abs(b[i]-c[i]));
		nw+=a[i-1]-1-abs(b[i]-c[i]),nw=max(nw,a[i-1]-1ll);
	}
	printf("%lld\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}