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

bool test(int x, vi &v) {
	int n = sz(v);
	ll inc = (1LL<<x) - 1LL;
	ll lstVal = v.back() + inc;
	for (int i=n-2; i >= 0; i--) {
		if (v[i] > lstVal) return false;

		lstVal = min(v[i] + inc, lstVal);
	}
	return true;
}

int run() {
	int n;
	scanf("%d", &n);
	vi v(n, 0);
	REP(i, n) scanf("%lld", &v[i]);

	int lo = -1, hi = 32;
	while (hi - lo > 1) {
		int mi = (lo + hi) / 2;
		// test mi.
		if (test(mi, v))
			hi = mi;
		else
			lo = mi;
	}
	return hi;
}

signed main() {
	int ntc;
	scanf("%d", &ntc);
	while (ntc--) {
		int ans = run();
		printf("%d\n", ans);
	}
	return 0;
}