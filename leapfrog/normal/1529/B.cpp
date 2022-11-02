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
int n,a[100005],v[100005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<n;i++) v[i]=a[i+1]-a[i];
	v[0]=1e9;for(int i=1;i<n;i++) v[i]=min(v[i],v[i-1]);
	for(int i=n;i;i--) if(a[i]<=v[i-1]) return printf("%d\n",i),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}