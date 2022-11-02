//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,a[1000005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int sm=0;for(int i=1;i<=n;i++) sm+=a[i];
	if(sm==n) return puts("0"),void();
	if(sm<n) return puts("1"),void();
	printf("%d\n",sm-n);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}