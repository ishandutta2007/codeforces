//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K,a[100005],tn[100005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),tn[i]=a[i];
	sort(tn+1,tn+n+1);for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+n+1,a[i])-tn;
	int rs=1;for(int i=2;i<=n;i++) if(a[i]!=a[i-1]+1) rs++;
	if(rs<=K) return puts("Yes"),void();else return puts("No"),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}