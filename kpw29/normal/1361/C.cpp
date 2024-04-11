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
using mint = modint1000000007;
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

/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */
 
vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	vector <pii> ret, s = {{src, -1}};
	while (!s.empty()) {
		pii x = s.back();
		int y, e, &it = its[x.first], end = sz(gr[x.first]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x.first][it++];
		if (!eu[e]) {
			D[x.first]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

vector<pii> cycle;
void solve(int tc) {
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];
	
	auto check = [&](int k) {
		int mask = (1 << (k)) - 1;
		vector <vector<pii> > graf(1 << k);
		rep(i, 0, n) {
			graf[a[i] & mask].pb({b[i] & mask, i});
			graf[b[i] & mask].pb({a[i] & mask, i});
		}
		
		cycle = eulerWalk(graf, n, a[0] & mask);
		return sz(cycle) == n + 1;
	};
	
	int x = 20;
	while (!check(x)) --x;
	cout << x << "\n";
	
	//debug(cycle);
	int mask = (1 << x) - 1;
	vi out;
	rep(i, 1, sz(cycle)) {
		int e = cycle[i].e2;
		int n1 = 2 * e + 1, n2 = 2 * e + 2;
		if ((a[e] & mask) == cycle[i - 1].e1 && (b[e] & mask) == cycle[i].e1);
		else {
			assert(((a[e] & mask) == cycle[i].e1 && (b[e] & mask) == cycle[i - 1].e1));
			swap(n1, n2);
		}
		
		out.pb(n1); out.pb(n2);
	}
	
	trav(node, out) cout << node << ' ';
	cout << "\n";
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}