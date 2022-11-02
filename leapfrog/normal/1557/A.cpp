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
	ll sm=0;int mx=-1e9;for(int i=1;i<=n;i++) sm+=a[i],mx=max(mx,a[i]);
	printf("%.10lf\n",mx+1.0*(sm-mx)/(n-1));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}