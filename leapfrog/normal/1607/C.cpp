#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=200005;int n,a[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);int mx=a[1];
	for(int i=2;i<=n;i++) mx=max(mx,a[i]-a[i-1]);
	printf("%d\n",mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}