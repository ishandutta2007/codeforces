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
int T,n,m,K,a[100005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	a[n+1]=0;for(int i=1;i<=K;i++)
	{
		int x=1;char fg=0;
		while(a[x]>=a[x+1]&&x<=n) x++;
		if(x<=n) a[x]++;
		for(int j=1;j<n;j++) if(a[j]<a[j+1]) fg=1;
		if(!fg&&i!=K) return puts("-1"),void();
		if(i==K) printf("%d\n",x==n+1?-1:x);
	}
}
int main() {for(read(T);T--;) solve();return 0;}