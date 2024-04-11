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
	int n,i;read(n);
	for(i=1;i*(i-1)/2<=n;i++);i--;
	putchar('1'),putchar('3'),putchar('3');
	for(int j=i*(i-1)/2;j<n;j++) putchar('7');
	for(int j=1;j<=i-2;j++) putchar('3');
	putchar('7'),putchar('\n');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}