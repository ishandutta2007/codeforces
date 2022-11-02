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
int Ca,n,a[1000005];
inline void solve()
{
	read(n),n<<=1;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),printf("%d\n",a[(n>>1)+1]-a[n>>1]);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}