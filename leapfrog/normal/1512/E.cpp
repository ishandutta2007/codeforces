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
int Ca,n,l,r,len,sm,a[505],b[505];char v[505];
inline void solve()
{
	read(n),read(l),read(r),read(sm),len=r-l+1,memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));for(int i=1;i<=len;i++) a[i]=i,sm-=i;
	if(sm<0) return puts("-1"),void();
	for(int i=len;i&&sm;i--) if(n-len>=sm) a[i]+=sm,sm=0;else a[i]+=n-len,sm-=n-len;
	if(sm) return puts("-1"),void();else for(int i=1;i<=n;i++) v[a[i]]=1;
	int bc=0;for(int i=1;i<=n;i++) if(!v[i]) b[++bc]=i;
	int wh=1;for(int i=1;i<l;i++) printf("%d ",b[wh++]);
	for(int i=1;i<=len;i++) printf("%d ",a[i]);
	for(int i=r+1;i<=n;i++) printf("%d ",b[wh++]);
	putchar('\n');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}