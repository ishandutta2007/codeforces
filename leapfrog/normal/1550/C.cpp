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
int n,a[200005];
//1 2 3 4
inline int chk(int a,int b,int c)
{
	if(a<=b&&b<=c) return 0;
	if(a>=b&&b>=c) return 0;
	return 1;
}
inline int ck2(int a,int b,int c,int d)
{
	if(!chk(a,b,c)) return 0;
	if(!chk(b,c,d)) return 0;
	if(!chk(a,b,d)) return 0;
	if(!chk(a,c,d)) return 0;
	return 1;
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int rs=n+n-1;for(int i=1;i<n-1;i++) rs+=chk(a[i],a[i+1],a[i+2]);
	for(int i=1;i<n-2;i++) rs+=ck2(a[i],a[i+1],a[i+2],a[i+3]);
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}