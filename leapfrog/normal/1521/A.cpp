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
int Ca,n,m,K,a[1000005];char ch[1000005];
inline void solve()
{
	int A,B;read(A),read(B);
	if(B==1) return puts("NO"),void();else puts("YES");
	if(B==2) printf("%d %d %d\n",A,A*3,A*4);else printf("%d %lld %lld\n",A,1ll*A*(B-1),1ll*A*B);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}