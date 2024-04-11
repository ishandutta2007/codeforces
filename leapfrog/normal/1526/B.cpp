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
	//111%11=1
	int x;read(x);
	int cn=x%11;if(x-111*cn<0) puts("NO");else puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}