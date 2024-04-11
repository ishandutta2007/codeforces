//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,fa[400005],v[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline void solve()
{
	read(n),read(m);for(int i=1;i<=n+n;i++) fa[i]=i;
	ll sm=0;for(int i=1;i<=n;i++) read(v[i]);
	for(int i=1,x;i<=n;i++) read(x),v[i]-=x,sm+=v[i];
	for(int i=1,x,y;i<=m;i++) read(x),read(y),mrg(x,y+n),mrg(y,x+n);
	int sz=0;if(sm&1) return puts("NO"),void();
	for(int i=1;i<=n+n;i++) sz+=getf(i)==getf(1);
	if(sz==n+n) return puts("YES"),void();
	ll ss=0;for(int i=1;i<=n;i++) if(getf(i)==getf(1)) ss+=v[i];else ss-=v[i];
	return puts(ss?"NO":"YES"),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}