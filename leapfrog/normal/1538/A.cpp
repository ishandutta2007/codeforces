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
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	int mx=0,mn=1e9;for(int i=1;i<=n;i++) mx=max(mx,a[i]),mn=min(mn,a[i]);
	int l=0,r=0;for(int i=1;i<=n;i++) if(a[i]==mx) l=i;else if(a[i]==mn) r=i;
	if(l>r) swap(l,r);
	printf("%d\n",min(min(r,n-l+1),n-r+1+l));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}