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
int T,n,a[200005],b[200005],c[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	b[0]=0;for(int i=1;i<=n;i++) b[i]=a[i]>=b[i-1]&&~b[i-1]?a[i]-b[i-1]:-1;
	c[n+1]=0;for(int i=n;~i;i--) c[i]=a[i]>=c[i+1]&&~c[i+1]?a[i]-c[i+1]:-1;
	if(!b[n]) return puts("YES"),void();
	for(int i=1;i<n;i++) if(~b[i-1]&&~c[i+2]&&b[i-1]<=a[i+1]&&c[i+2]<=a[i]&&a[i+1]-b[i-1]==a[i]-c[i+2]) return puts("YES"),void();
	return puts("NO"),void();
}
int main() {for(read(T);T--;) solve();return 0;}