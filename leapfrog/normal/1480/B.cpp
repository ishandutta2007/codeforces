//
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=1000005;int T,A,B,n,m,K;pair<int,int>a[N];
inline void solve()
{
	read(A),read(B),read(n);int mx=0;
	for(int i=1;i<=n;i++) read(a[i].first),mx=max(mx,a[i].first);
	for(int i=1;i<=n;i++) read(a[i].second);
	for(int i=1;i<=n;i++) B-=(a[i].second+A-1)/A*a[i].first;
	B+=mx;if(B<=0) puts("NO");else puts("YES");
}
signed main() {for(read(T);T--;) solve();return 0;}