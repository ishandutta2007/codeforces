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
int n,a[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	char fg=0;for(int i=1;i<n;i++) if(a[i]>a[i+1]) fg=1;
	if(!fg) printf("%d\n",0);else printf("%d\n",3-(a[1]!=n||a[n]!=1)-(a[1]==1||a[n]==n));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}