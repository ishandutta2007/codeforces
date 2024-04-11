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
int Ca,n,a[200005],tn[400005];ll res=0;
inline void solve()
{
	read(n),res=0;const int N=200001;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=-n-1;i<=n+1;i++) tn[i+N]=0;
	for(int i=1;i<=n;i++) res+=tn[a[i]-i+N],tn[a[i]-i+N]++;
	printf("%lld\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}