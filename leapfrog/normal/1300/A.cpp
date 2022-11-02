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
int Ca,n,m,K,a[1000005];char ch[1000005];
inline void solve()
{
	int sm=0,cnt=0;read(n);for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	for(int i=1;i<=n;i++) if(!a[i]) a[i]++,sm++,cnt++;
	printf("%d\n",cnt+!sm);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}