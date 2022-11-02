#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;ll a[200005],d[200005];
inline void solve()
{
	char tag=1;ll sm=0;read(n),n<<=1;for(int i=1;i<=n;i++) read(d[i]);
	sort(d+1,d+n+1);for(int i=1;i<=n&&tag;++++i) if(d[i]^d[i+1]) tag=0;
	if(d[n]%n) tag=0;else a[n]=d[n]/n,a[n-1]=-a[n],sm=a[n]+a[n];
	for(int i=n-2;i>1&&tag;----i)
	{
		if(d[i]<=sm||(d[i]-sm)%i) tag=0;else a[i]=(d[i]-sm)/i,a[i-1]=-a[i];
		if(a[i]==a[i+2]) tag=0;else sm+=a[i]+a[i];
	}
	if(tag) puts("YES");else puts("NO");
}
int main() {for(read(T);T--;) solve();return 0;}