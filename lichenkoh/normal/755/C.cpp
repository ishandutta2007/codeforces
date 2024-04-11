#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll mn=1e4+4;
ll p[mn];
ll find(ll x) {
	if (p[x] != x) {
		p[x] = find(p[x]);
	}
	return p[x];
}
void funion(ll x, ll y) {
	if (rand()&1) swap(x,y); 
	ll xr = find(x);
	ll yr = find(y);
	p[xr] = yr;
}
ll a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll x=1;x<=n;x++) scanf("%lld",&a[x]);
	for (ll x=1;x<=n;x++) p[x]=x;
	for (ll x=1;x<=n;x++) {
		funion(x,a[x]);
	}
	ll ans=0;
	for (ll x=1;x<=n;x++) {
		if (p[x]==x) ans++;
	}
	printf("%lld\n",ans);
}