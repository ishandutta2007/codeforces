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

const int MAXE = 200'000;
vii E[MAXE];
vi to[MAXE];

int K, K2;

int to_idx(int i, int ci) {
	// 0 <= i < 9
	// 0 <= ci < i
	return i*(i-1)/2 + ci;
}

// each set is at most 10*9/2 = 45 in size.
vector<int> is_nth[MAXE]; // one of these (i, c_i) is required

bool notboth[45][45] = {};
int bucket[45] = {};

int res = 0;
set<int> excl;

void recurse(vi &v, int i) {
	if (i == K) {
		REP(i, K) REP(j, i)
			if (notboth[v[i]][v[j]]) {
				return;
			}

		/* for (int x : v) cerr << x <<",";
		cerr << endl; */

		res++;
		return;
	}

	for (int val = 0; val <= i; val++) {
		if (excl.find(to_idx(i+1, val)) != excl.end()) continue;
		v.pb(to_idx(i+1, val));
		recurse(v, i+1);
		v.pop_back();
	}
}

void run() {
	int n, m, k;
	cin >> n >> m >> k;

	K = k;
	K2 = k*(k+1)/2;

	REP(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u-1].eb(w, v-1);
	}

	// order outgoing edges:
	REP(i, n) {
		sort(all(E[i]));
		for (auto [w,v] : E[i]) to[i].pb(v);
	}

	REP(v, n) {
		int k = sz(to[v]);
		REP(j, k) {
			int w = to[v][j];
			// v -> w.
			is_nth[w].eb(to_idx(k, j));
		}
	}

	// O(n * 45)
	REP(v, n) {

		/* cerr << "incoming " << v << endl;
		for (int x : is_nth[v]) cerr << x << " ";
		cerr << endl; */

		REP(i, K2) bucket[i] = 0;
		for (int x : is_nth[v]) bucket[x]++;

		REP(i, K2) {
			if (bucket[i] >= 2) {
				excl.insert(i);
				bucket[i] = 0;
			}
		}

		REP(i, K2) if (bucket[i] > 0) {
			REP(j, i) if (bucket[j] > 0) {
				notboth[i][j] = true;
			}
		}
	}

	vi vals;
	// cerr << "recursing" << endl;
	recurse(vals, 0);

/*
	vi perm;
	REP(i, k) perm.pb(i); // ={0,1,2,3,4,5,6,7,8};
	int res = 0;
	do {
		// is consistent?

		vi vals;
		REP(i, K) vals.eb(to_idx(i+1, perm[i]));
		bool valid = true;

		for (int x : perm) cerr << x;
		cerr << " -> ";
		for (int x : vals) cerr << x << " ";
		cerr << endl;

		REP(i, K) REP(j, i)
			if (notboth[vals[i]][vals[j]]) {
				valid = false; break;
			}

		if (valid) {
			res++;
		}
	} while (next_permutation(all(perm)));
*/
	cout << res << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}