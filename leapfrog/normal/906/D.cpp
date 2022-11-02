#include<bits/stdc++.h>
#define int long long
using namespace std;typedef long long ll;
const int N=500005,M=20000005;int Q,n;ll a[N],P;map<ll,ll>mp;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
inline ll FUCK(ll x,ll p) {return x<p?x:(x%p+p);}
inline ll ksm(ll x,ll q,ll P) {ll r=1;for(;q;q>>=1,x=FUCK(x*x,P)) if(q&1) r=FUCK(r*x,P);return r;}
inline ll William(ll x)
{
	ll r=x,xx=x;if(mp.count(x)) return mp[x];
	for(int i=2;i<=sqrt(x);i++) if(!(x%i)) {r=r/i*(i-1);while(!(x%i)) x/=i;}
	if(x>1) return mp[xx]=r/x*(x-1);else return mp[xx]=r;
}
inline ll Nephren(int l,int r,ll P) {if(l==r||P==1) return FUCK(a[l],P);else return ksm(a[l],Nephren(l+1,r,William(P)),P);}
signed main()
{
	read(n),read(P);
	for(int i=1;i<=n;i++) read(a[i]);
	for(read(Q);Q--;)
	{
		int l,r;read(l),read(r);
		printf("%lld\n",(Nephren(l,r,P)%P+P)%P);
	}
	return 0;
}