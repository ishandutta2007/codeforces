#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) begin(v), end(v)
#define sz(v) ((int) (v).size())
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " \
		<< #x<< " = " << (x) << endl

template<class T> ostream& operator<<(ostream &os,
		const vector<T> &v) {
	os << "\n[";
	for(const T &x : v) os << x << ',';
	return os << "]\n";
}

namespace std { template<class T1, class T2>
struct hash<pair<T1,T2>> { public:
	size_t operator()(const pair<T1,T2> &p) const {
		size_t x = hash<T1>()(p.x), y = hash<T2>()(p.y);
		return x ^ (y + 0x9e3779b9 + (x<<6) + (x>>2));
	}
}; }

ll run(ll n) {
	--n;

	if (n < 3) {
		return (ll[3]) { 1, 2, 3 }[n];
	}

	ll nk = n / 3LL - 1;
	ll p4 = 4LL;
	int nbits = 4;
	while (nk >= p4) {
		nk -= p4;
		p4 *= 4LL;
		nbits += 2;
	}

	assert(0 <= nk && nk < p4);

	ll a = 1LL << (nbits - 2);
	ll b = 2LL << (nbits - 2);
	ll c = 3LL << (nbits - 2);

	int shift = 0;
	for (int i=0; i < nbits/2; i++) {
		a |= (ll[4]){ 0, 1, 2, 3 }[nk%4] << shift;
		b |= (ll[4]){ 0, 2, 3, 1 }[nk%4] << shift;
		c |= (ll[4]){ 0, 3, 1, 2 }[nk%4] << shift;

		nk /= 4;
		shift += 2;
	}

	return (ll[3]){ a, b, c }[n % 3];
}

signed main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", run(x));
	}
	return 0;
}