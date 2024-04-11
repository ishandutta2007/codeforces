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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;
int n,a[N],b[N],c1[N],c2[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i],b[i]);
	ll rs=1ll*n*(n-1)/2*(n-2)/3;
	for(int i=1;i<=n;i++) c1[i]=c2[i]=0;
	for(int i=1;i<=n;i++) c1[a[i]]++,c2[b[i]]++;
	for(int i=1;i<=n;i++) rs-=1ll*(c1[a[i]]-1)*(c2[b[i]]-1);
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}