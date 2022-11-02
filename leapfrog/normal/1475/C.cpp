//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,A,B,n,a[200005],b[200005],X[200005],Y[200005];ll res=0;
inline void solve()
{
	read(A),read(B),read(n),res=0,memset(X+1,0,A<<2),memset(Y+1,0,B<<2);
	for(int i=1;i<=n;i++) read(a[i]),X[a[i]]++;
	for(int i=1;i<=n;i++) read(b[i]),Y[b[i]]++;
	for(int i=1;i<=n;i++) res+=n-X[a[i]]-Y[b[i]]+1;
	printf("%lld\n",res>>1);
}
int main() {for(read(T);T--;) solve();return 0;}