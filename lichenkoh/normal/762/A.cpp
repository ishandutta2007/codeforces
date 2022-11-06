#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld%lld",&n,&k);
	ll dlim=min((ll)sqrt((ld)n)+2LL,(ll)n);
	vector<ll> vd;
	for (ll d=1;d<=dlim;d++) {
		ll x=n/d;
		if (x*d==n) {
			if (x>=d) vd.PB(d);
			if (x>d) vd.PB(x);
		}
	}
	sort(vd.begin(),vd.end());
	//for (auto &d:vd) printf("%lld ",d);
	//printf("\n");
	if (k>vd.size()) printf("-1\n");
	else printf("%lld\n",vd[k-1]);
}