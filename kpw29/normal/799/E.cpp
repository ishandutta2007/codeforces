#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
/*#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
vector <mint> fac, inv;
mint binom(int n, int k) {
	if (n < k || n < 0) return 0;
	return fac[n] * inv[k] * inv[n-k];
}

void prep(int N) {
	fac.resize(N+1, 1); inv.resize(N+1, 1);
	for (int i=1; i<=N; ++i) fac[i] = fac[i-1] * i;
	inv[N] = fac[N].inv();
	for (int i=N-1; i>0; --i) inv[i] = inv[i+1] * (i + 1);
}*/

mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
const int maxn = 1000100;
const ll INF = 1e18 + 3;

const int R = (1 << 18);
ll sum[2 * R + 5];
int ile[2 * R + 5];

ll search(int k) {
	if (k == 0) return 0;
	if (k < 0) return INF;
	if (k > ile[1]) return INF;
	ll res = 0;
	int x = 1;
	while (x < R) {
		int lewy = 2 * x;
		if (ile[lewy] >= k) x = lewy;
		else {
			k -= ile[lewy];
			res += sum[lewy];
			x = lewy + 1;
		}
	}
	
	return res + sum[x];
}

void add(int pos, int krotnosc, ll value) {
	int x = pos + R - 1;
	while (x) {
		ile[x] += krotnosc;
		sum[x] += value * krotnosc;
		x >>= 1;
	}
}

//Did you REAALLY consider sample tests?
bool f1[maxn], f2[maxn];
ll init[maxn];

int cost[maxn];
int n, m, k;
vector <pii> v[2][2];
int tab[maxn];

void solve(int tc) {
	cin >> n >> m >> k;
	FOR(i, 1, n) cin >> init[i];
	int a;
	cin >> a;
	FOR(i, 1, a) {
		int fl;
		cin >> fl;
		f1[fl] = 1;
	}
	cin >> a;
	FOR(i, 1, a) {
		int fl;
		cin >> fl;
		f2[fl] = 1;
	}
	vector <pii> skal;
	FOR(i, 1, n) {
		skal.pb({init[i], i});
	}
	sort(all(skal));
	rep(i, 0, n) {
		auto &[value, pos] = skal[i];
		tab[pos] = i + 1;
	}
	
	FOR(i, 1, n) {
		v[f1[i]][f2[i]].pb({tab[i], i});
	}
	
	rep(a, 0, 2) rep(b, 0, 2) {
		sort(all(v[a][b]));
	}
	
	debug(v[0][0]);
	debug(v[0][1]);
	debug(v[1][0]);
	debug(v[1][1]);
	
	int s = sz(v[1][1]);
	ll best = INF;
	ll curr = 0;
	// add all initials
	int taken_prefix = k;
	rep(i, 0, min(taken_prefix, sz(v[1][0]))) {
		auto &[value, pos] = v[1][0][i];
		curr += init[pos];
	}
	
	rep(i, 0, min(taken_prefix, sz(v[0][1]))) {
		auto &[value, pos] = v[0][1][i];
		curr += init[pos];
	}
	
	// add other things
	rep(i, taken_prefix, sz(v[1][0])) {
		auto &[value, pos] = v[1][0][i];
		add(value, 1, init[pos]);
	}
	rep(i, taken_prefix, sz(v[0][1])) {
		auto &[value, pos] = v[0][1][i];
		add(value, 1, init[pos]);
	}
	rep(i, 0, sz(v[0][0])) {
		auto &[value, pos] = v[0][0][i];
		add(value, 1, init[pos]);
	}
	
	debug(curr);
	rep(wezme, 0, s+1) {
		if (wezme > 0) {
			auto &[value, pos] = v[1][1][wezme-1];
			curr += init[pos];
			if (taken_prefix > 0) {
				--taken_prefix;
				if (taken_prefix < sz(v[0][1])) {
					auto &[value, pos] = v[0][1][taken_prefix];
					add(value, 1, init[pos]);
					curr -= init[pos];
				}
				
				if (taken_prefix < sz(v[1][0])) {
					auto &[value, pos] = v[1][0][taken_prefix];
					add(value, 1, init[pos]);
					curr -= init[pos];
				}
			}
		}
		int needs = m - 2 * taken_prefix - wezme;
		debug(wezme, curr, taken_prefix, needs);

		if (taken_prefix <= min(sz(v[0][1]), sz(v[1][0]))) {
			best = min(best, curr + search(m - 2 * taken_prefix - wezme));
		}
	}
	
	if (best == INF) cout << "-1" << endl;
	else cout << best << endl;
	
}

int main() {
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}