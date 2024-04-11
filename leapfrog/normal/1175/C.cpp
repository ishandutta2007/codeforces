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
int n,K,a[200005];
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	for(int i=1;i+K<=n;i++) q.push(make_pair(a[i+K]-a[i],a[i]+(a[i+K]-a[i])/2));
	printf("%d\n",q.top().second);
}
signed main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}