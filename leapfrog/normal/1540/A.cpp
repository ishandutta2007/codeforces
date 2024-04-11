//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,a[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);ll rs=0;for(int i=n;i;i--) a[i]-=a[i-1];
	for(int i=1;i<n;i++) rs+=a[i+1]*(1ll*i*(n-i)-1);
	printf("%lld\n",-rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}