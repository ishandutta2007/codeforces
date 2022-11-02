//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
inline void solve()
{
	int n;read(n);int mx=0;
	while(n) mx=max(mx,n%10),n/=10;
	printf("%d\n",mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}