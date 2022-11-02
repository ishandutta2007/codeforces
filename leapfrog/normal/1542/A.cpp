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
	int n,cn[2]={0,0};read(n);
	for(int i=1,x;i<=n+n;i++) read(x),cn[x&1]++;
	if(cn[1]==cn[0]) puts("Yes");else puts("No");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}