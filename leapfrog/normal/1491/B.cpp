//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,U,V,a[100005];
inline void solve()
{
	read(n),read(U),read(V);int tag=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) if(a[i-1]-1>a[i]||a[i-1]+1<a[i]) tag=1;
	if(tag) return puts("0"),void();else tag=0;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) tag=1;
	if(tag) printf("%d\n",min(U,V));else printf("%d\n",V+min(U,V));
}
int main() {for(read(Ca);Ca--;) solve();return 0;}