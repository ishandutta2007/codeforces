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
const int N=100005;
int T,n,m,K;char a[N];
inline void solve()
{
	read(n),read(K),scanf("%s",a+1);
	for(int i=1;i<=K;i++) if(a[i]!=a[n-i+1]) return puts("NO"),void();
	if(K+K==n) puts("NO");else puts("YES");
}
int main() {for(read(T);T--;) solve();return 0;}