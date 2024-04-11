//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[200005];ll sm[200005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--) {sm[i]=a[i];if(i+a[i]<=n) sm[i]+=sm[i+a[i]];}
	ll mx=0;for(int i=1;i<=n;i++) mx=max(mx,sm[i]);
	printf("%lld\n",mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}