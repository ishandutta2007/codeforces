//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[1000005];
inline void solve()
{
	read(n);int sm=0;for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	if(sm%n) return puts("-1"),void();else sm/=n;
	int cnt=0;for(int i=1;i<=n;i++) cnt+=a[i]>sm;
	printf("%d\n",cnt);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}