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
int T,n,a[1005][1005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%1d",a[i]+j);
	for(int i=1,x;i<=n;i++) for(int j=1;j<=n;j++) scanf("%1d",&x),a[i][j]^=x;
	for(int i=2;i<=n;i++) for(int j=2;j<=n;j++) if(a[i][j]^a[i][1]^a[1][j]^a[1][1]) return puts("NO"),void();
	puts("YES");
}
int main() {for(read(T);T--;) solve();return 0;}