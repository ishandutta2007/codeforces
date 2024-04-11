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
int T,n,a[300005];
inline void solve()
{
	read(n),a[n+1]=0;for(int i=1;i<=n;i++) read(a[i]);
	int mx=0;for(int i=1;i<=n;i++) a[0]=a[n+1]=mx=max(mx,a[i]);
	for(int i=1;i<=n;i++) if(a[i]==mx&&(a[i-1]!=mx||a[i+1]!=mx)) return printf("%d\n",i),void();
	puts("-1");
}
int main() {for(read(T);T--;) solve();return 0;}