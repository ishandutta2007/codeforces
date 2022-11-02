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
inline void solve()
{
	int n,a,b;read(n),read(a),read(b);
	if(a==1) {if((n-1)%b==0) puts("Yes");else puts("No");return;}
	for(ll i=1;i<=n;i*=a) if((n-i)%b==0) return puts("Yes"),void();
	puts("No");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}