//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
map<set<int>,ll>mp;int T,n,m;ll a[500005];set<int>v[500005];
inline ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
inline void solve()
{
	read(n),read(m),mp.clear();for(int i=1;i<=n;i++) v[i].clear();
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),v[y].insert(x);
	for(int i=1;i<=n;i++) if(!v[i].empty()) mp[v[i]]+=a[i];
	ll g=0;for(auto i:mp) if(g) g=gcd(g,i.second);else g=i.second;
	printf("%lld\n",g);
}
int main() {for(read(T);T--;) solve();return 0;}