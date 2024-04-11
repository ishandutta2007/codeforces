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

int rocc[100'000] = {}, occ[100'000] = {};

bool test(int n, int D) {
	priority_queue<ii> pq;

	vvi evts(n);
	REP(i, n) {
		occ[i] = rocc[i];
		if (occ[i]) evts[0].pb(i);
	}

	vi nrs;
	for (int idx = 0; idx < n; idx++) {
		// we need to place something here
		for (int i : evts[idx])
			pq.emplace(occ[i], i);

		if (pq.empty()) {

			/* cout << D << " (nope): ";
			for (int v : nrs) cout << v << " ";
			cout << endl; */

			return false;
		}
		ii cur = pq.top();
		pq.pop();

		nrs.pb(cur.y+1);

		if (--occ[cur.y] > 0 && idx + D + 1 < n) {
			evts[idx+D+1].pb(cur.y);
		}
	}
/*
	cout << D << ": ";
	REP(i, n) cout << nrs[i] << " ";
	cout << endl;
*/
	return true;
}

void run() {
	int n;
	cin >> n;

	REP(i, n) rocc[i] = 0;
	REP(i, n) {
		int x;
		cin >> x;
		rocc[x-1]++;
	}

	int lo = 0, hi = n;
	while (hi - lo > 1) {
		int mi = (lo+hi)/2;
		if (test(n, mi)) lo = mi;
		else hi = mi;
	}
	cout << lo << endl;

	// REP(i, n) if (occ[i]) pq.emplace(-0, 
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int t;
	cin >> t;
	while (t--) run();
	return 0;
}