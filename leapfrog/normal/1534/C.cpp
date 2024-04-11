//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,a[400005],v[400005],fa[400005];const int P=1e9+7;
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void solve()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),a[x]=i;
	for(int i=1;i<=n;i++) read(v[i]),fa[i]=i;
	for(int i=1;i<=n;i++) mrg(i,a[v[i]]);
	int cnt=0;for(int i=1;i<=n;i++) cnt+=getf(i)==i;
	printf("%d\n",ksm(2,cnt));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}