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
int Ca,n,a[100005];
inline void solve()
{
	read(n);int cnt=0;
	if(n==1) return puts("1"),void();
	if(n==2) return puts("-1"),void();
	for(int i=1;i<=n*n;i+=2) a[++cnt]=i;
	for(int i=2;i<=n*n;i+=2) a[++cnt]=i;
	cnt=0;for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",a[++cnt],j==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}