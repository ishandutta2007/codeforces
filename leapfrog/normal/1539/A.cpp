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
int n,x,t;
inline void solve()
{
	read(n),read(x),read(t);
	int ln=t/x;printf("%lld\n",1ll*max(n-ln,0)*ln+1ll*min(n,ln)*(min(n,ln)-1)/2);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}