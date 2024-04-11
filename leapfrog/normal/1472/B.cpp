//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,a[100005];
inline void solve()
{
	read(n);int tot=0;for(int i=1;i<=n;i++) read(a[i]),tot+=a[i];
	if(tot&1) return puts("NO"),void();
	int cn=0;for(int i=1;i<=n;i++) if(a[i]==2) cn++;
	if(cn%2==0) return puts("YES"),void();
	if(n==cn) return puts("NO"),void();else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}