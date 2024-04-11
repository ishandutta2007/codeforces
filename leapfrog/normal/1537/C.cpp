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
int n,a[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	if(n==2) return printf("%d %d\n",min(a[1],a[2]),max(a[1],a[2])),void();
	sort(a+1,a+n+1);int mn=1e9,pos=0;
	for(int i=1;i<n;i++) if(mn>a[i+1]-a[i]) mn=a[i+1]-a[i],pos=i+1;
	for(int i=pos;i<=n;i++) printf("%d ",a[i]);
	for(int i=1;i<pos;i++) printf("%d ",a[i]);
	putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}