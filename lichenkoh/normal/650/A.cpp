#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
map<ll,ll> hx,hy;
map<pair<ll,ll>,ll > hs;
int main() {
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		hx[x]++;
		hy[y]++;
		hs[MP(x,y)]++;
	}
	ll ans=0;
	for (auto &w:hs) {
		ll t=w.second;
		ans-=(t*(t-1))/2;
	}
	for (auto &w:hx) {
		ll t=w.second;
		ans+=(t*(t-1))/2;
	}
	for (auto &w:hy) {
		ll t=w.second;
		ans+=(t*(t-1))/2;
	}
	printf("%lld\n",ans);
}