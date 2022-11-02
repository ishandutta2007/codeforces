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
	int l=0;for(int i=n;i>=1;i--) if(a[i]) l=i;
	int r=0;for(int i=1;i<=n;i++) if(a[i]) r=i;
	int cnt=0;for(int i=l;i<=r;i++) if(!a[i]) cnt++;
	printf("%d\n",cnt);
}
int main() {for(read(T);T--;) solve();return 0;}