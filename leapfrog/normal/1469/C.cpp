//{{{
#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int Ca,n,K,a[200005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	int l=a[1],r=a[1];for(int i=2;i<=n;i++)
	{
		int dl=max(a[i],l+1-K),dr=min(a[i]+K-1,r-1+K);
		l=dl,r=dr;if(l>r||l-a[i]>=K) return puts("NO"),void();
	}
	if(l==a[n]) puts("YES");else puts("NO");
}
signed main() {for(read(Ca);Ca--;) solve();return 0;}