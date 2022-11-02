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
const int N=200005;int n,a[N];map<ll,int>mp;
inline void solve()
{
	read(n),mp.clear();for(int i=1;i<=n;i++) read(a[i]);
	ll rs=0;for(int i=1;i<=n;i++) rs+=a[i];
	rs*=2;if(rs%n) return puts("0"),void();else rs/=n;
	ll res=0;for(int i=1;i<=n;i++) res+=mp[rs-a[i]],mp[a[i]]++;
	printf("%lld\n",res);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}