//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,x,a[1000005];ll sm=0;
inline void solve()
{
	read(n),read(x),sm=0;for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	ll nw=0;if(sm==x) return puts("NO"),void();else puts("YES");
	sort(a+1,a+n+1,greater<int>());for(int i=1;i<=n;i++)
	{
		if(nw+a[i]==x) swap(a[i],a[i+1]);
		nw+=a[i],printf("%d%c",a[i],i==n?'\n':' ');
	}
}
int main() {for(read(Ca);Ca--;) solve();return 0;}