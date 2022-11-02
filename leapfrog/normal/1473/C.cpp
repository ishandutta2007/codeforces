//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,n,K,a[100005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=K;i++) a[i]=i;
	if(n>K) reverse(a+K+K-n,a+K+1);
	for(int i=1;i<=K;i++) printf("%d%c",a[i],i==K?'\n':' ');
}
int main() {for(read(T);T--;) solve();return 0;}