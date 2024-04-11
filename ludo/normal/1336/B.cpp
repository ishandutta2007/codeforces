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

int n[3];
vi v[3];
set<int> m[3];

ll D(int x, int y, int z) {
	return ll(x-y)*ll(x-y) + ll(x-z)*ll(x-z) + ll(z-y)*ll(z-y);
}

ll try_xy(int x, int y, int i) {
	// find z closest to (x+y)/2
	auto it = m[i].lower_bound(int((x+y)/2));
	ll res = LLONG_MAX;
	if (it != m[i].end()) {
		res = min(res, D(x, y, *it));
	}
	if (it != m[i].begin()) {
		--it;
		res = min(res, D(x, y, *it));
	}
	return res;
}

ll run() {
	scanf("%d%d%d", &n[0], &n[1], &n[2]);

	REP(i, 3) {
		v[i].clear();
		v[i].resize(n[i]);
		REP(j, n[i]) scanf("%lld", &v[i][j]);

		m[i].clear();
		for (int x : v[i]) m[i].insert(x);
	}

	ll res = LLONG_MAX;

	// calculate.
	REP(i, 3) {
		for (int x : v[i]) {
			// find y closest to x (on both sides)
			REP(j, 3) if (j != i) {
				auto it = m[j].lower_bound(x);
				if (it != m[j].end()) {
					ll alt = try_xy(x, *it, 3-i-j);
					res = min(res, alt);
				}
				if (it != m[j].begin()) {
					--it;
					ll alt = try_xy(x, *it, 3-i-j);
					res = min(res, alt);
				}
			}
		}
	}
	return res;
}

signed main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll ans = run();
		printf("%lld\n", ans);
	}

	return 0;
}