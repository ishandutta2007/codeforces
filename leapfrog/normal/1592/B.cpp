#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...dl) {read(x),read(dl...);}/*}}}*/
const int N=2000005;int n,K,a[N];
inline void solve()
{
	read(n,K);for(int i=1;i<=n;i++) read(a[i]);
	if(K<=n/2) return puts("YES"),void();
	int dl=n-K+1,dr=K;priority_queue<int>q;
	for(int i=1;i<dl;i++) q.push(-a[i]);
	for(int i=dr+1;i<=n;i++) q.push(-a[i]);
	for(int i=1;i<dl;i++) a[i]=-q.top(),q.pop();
	for(int i=dr+1;i<=n;i++) a[i]=-q.top(),q.pop();
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) return puts("NO"),void();
	puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}