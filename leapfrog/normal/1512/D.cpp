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
int Ca,n,a[200005];ll sm[200005];
inline void solve()
{
	read(n),n+=2;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	if(sm[n-2]==a[n-1]) {for(int i=1;i<n-1;i++) printf("%d%c",a[i],i==n-2?'\n':' ');return;}
	ll qwq=sm[n-1]-a[n];int wh=0;for(int i=1;i<n;i++) if(a[i]==qwq) wh=i;
	if(!wh) puts("-1");else {for(int i=1;i<n;i++) if(i^wh) printf("%d ",a[i]);putchar('\n');}
}
int main() {for(read(Ca);Ca--;) solve();return 0;}