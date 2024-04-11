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
	read(n),read(m),read(K);int cnt=0;
	while(n%2==0) n/=2,cnt++;
	while(m%2==0) m/=2,cnt++;
	int r=1;for(int i=1;i<=cnt;i++) r<<=1;
	if(r>=K) puts("YES");else puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}