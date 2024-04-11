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

const int N = 200'000;
vi E[N];
int D[N], S[N];

vector<ii> srt;
int ind[N] = {};

void dfs(int u, int v) {
	S[v] = 1;
	for (int w : E[v]) if (w != u) {
		D[w] = D[v] + 1;
		dfs(v, w);
		S[v] += S[w];
	}

	// srt.eb(make_pair(-D[v], S[v]), v);
	srt.eb( S[v] - D[v], v);
}

ll calc_ans(int u, int v) {
	bool was_ind = ind[v] != 0;
	ll res = 0;
	for (int w : E[v]) if (w != u) {
		res += calc_ans(v, w);
		ind[v] += ind[w];
	}

	if (!was_ind)
		res += ind[v];
	return res;
}

void run() {
	int n, k;
	cin >> n >> k;
	REP(_, n-1) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		E[u].pb(v);
		E[v].pb(u);
	}

	D[0] = 0;
	dfs(0, 0);

	sort(all(srt));

	for (int i=0; i<k; i++) {
		ind[ srt[i].y ] = 1;
	}

	cout << calc_ans(0, 0) << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}