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
int T,n,a[200005],rs,c1,c2;ll m,a1[200005],a2[200005];
inline ll min(ll a,ll b) {return a<b?a:b;}
inline int qry(ll x) {return x<=0?0:(x>a1[c1]?1e9+5:lower_bound(a1+1,a1+c1+1,x)-a1);}
inline void solve()
{
	read(n),read(m),rs=1e9,c1=0,c2=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,x;i<=n;i++) read(x),x&1?a1[++c1]=a[i]:a2[++c2]=a[i];
	sort(a1+1,a1+c1+1,greater<ll>());for(int i=1;i<=c1;i++) a1[i]+=a1[i-1];
	sort(a2+1,a2+c2+1,greater<ll>());for(int i=1;i<=c2;i++) a2[i]+=a2[i-1];
//	for(int i=1;i<=c1;i++) printf("%lld%c",a1[i],i==c1?'\n':' ');
	for(int i=0;i<=c2;i++) if(a1[c1]+a2[i]>=m) rs=min(rs,qry(m-a2[i])+i*2);
	printf("%d\n",rs==1000000000?-1:rs);
}
int main() {for(read(T);T--;) solve();return 0;}