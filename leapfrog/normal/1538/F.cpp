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
int n,m,K,a[2000005],b[2000005];char ch[2000005];ll N,M;
inline void solve()
{
	read(n),read(m);ll res=0,f=1;
	for(int i=0;i<=9;i++,f*=10) res+=m/f-n/f;
	printf("%lld\n",res);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}