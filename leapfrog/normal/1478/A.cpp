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
int T,n,cn[105];
inline void solve()
{
	memset(cn,0,sizeof(cn)),read(n);int mx=0;
	for(int i=1,x;i<=n;i++) read(x),cn[x]++;
	for(int i=1;i<=n;i++) mx=max(mx,cn[i]);
	printf("%d\n",mx);
}
int main() {for(read(T);T--;) solve();return 0;}