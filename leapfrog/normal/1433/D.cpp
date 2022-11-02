//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename t>inline void read(t &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int wh=0;for(int i=2;i<=n;i++) if(a[i]!=a[1]) wh=i;
	if(!wh) return puts("NO"),void();else puts("YES");
	for(int i=2;i<=n;i++) if(a[i]!=a[1]) printf("1 %d\n",i);else printf("%d %d\n",wh,i);
}
int main() {for(read(T);T--;) solve();return 0;}