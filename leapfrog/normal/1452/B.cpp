//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,a[N];
inline void solve()
{
	priority_queue<int,vector<int>,greater<int> >q;
	read(n);for(int i=1;i<=n;i++) read(a[i]),q.push(a[i]);
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	ll sm=0;for(int i=1;i<=n;i++) sm+=a[i];
	printf("%lld\n",max(1ll*mx*(n-1),(sm+n-2)/(n-1)*(n-1))-sm);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}