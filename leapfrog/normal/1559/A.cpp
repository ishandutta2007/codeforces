//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,K,a[2000005],b[2000005];char ch[2000005];ll N,M;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int sm=a[1];for(int i=2;i<=n;i++) sm&=a[i];
	printf("%d\n",sm);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}