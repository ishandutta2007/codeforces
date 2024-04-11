//
#include<bits/stdc++.h>
//#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=1000005;int T,n,a[100005];
inline int ask(int x)
{
	int g;if(a[x]) return a[x];else if(x==0||x==n+1) return 1e9;
	else return printf("? %d\n",x),fflush(stdout),read(g),a[x]=g;
}
inline void work(int l,int r)
{
	if(l==r) return printf("! %d\n",l),void();
	int md=(l+r)>>1,xa=ask(md),xb=ask(md+1);
	if(xa<xb) work(l,md);else work(md+1,r);
}
inline void solve() {read(n),work(1,n);}
signed main() {for(T=1;T--;) solve();return 0;}