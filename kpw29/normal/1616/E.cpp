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
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
	private:
	int n, size, log;
	vector<S> d;
	void update(int k) {d[k] = op(d[2 * k], d[2 * k + 1]); }
	public:
	segtree(const vector <S>&v) : n(sz(v)) {
		log = (32 - __builtin_clz(n)); size = 1 << log;
		d = vector<S>(2*size, e());
		rep(i, 0, n) d[size+i] = v[i];
		for (int i = size - 1; i >= 1; --i) update(i);
	}
	void set(int pos, S val) {
		pos += size; d[pos] = val;
        rep(i, 1, log + 1) update(pos >> i);
	}
	S prod(int l, int r) {
		S sml = e(), smr = e();
		for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
		}
		return op(sml, smr);
	}
};

int op(int a, int b){ return a + b; }
int id() {return 0; }

//Did you REAALLY consider sample tests?
ll solve(int tc) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector <vi> pos(26);
	
	s = "A" + s;
	t = "A" + t;
	
	string cop = s;
	sort(all(cop));
	if (cop >= t) return -1;
	if (s < t) return 0;
	
	int lcp = 0;
	while (lcp < n && s[lcp + 1] == t[lcp + 1]) ++lcp;
	
	for (int i=1; i<lcp; ++i) {
		if (s[i] > s[i + 1]) return 1;
	}
	
	//we know now that LCP is non-decreasing, the answer exists and is not 0
	ll option = (ll)n * n;
	FOR(i, lcp + 1, n) {
		if (s[i] < s[lcp]) option = min(option, (ll)i - lcp);
	}
	
	// now we know lcp is not touched
	for (int i=n; i>0; --i) pos[s[i] - 'a'].pb(i);
	rep(i, 0, 26) {
		while (!pos[i].empty() && pos[i].back() <= lcp) pos[i].pop_back();
	}
	
	ll curr = 0;
	
	vi ciag(sz(s));
	FOR(i, 0, lcp) ciag[i] = 0;
	rep(i, lcp+1, sz(s)) ciag[i] = 1;
	segtree<int, op, id> tree(ciag);
	
	for (int i=lcp+1; i<=n; ++i) {
		int co = t[i] - 'a';
		int first_position = n + 1;
		rep(lett, 0, co) {
			if (pos[lett].empty()) continue;
			first_position = min(first_position, pos[lett].back());
		}
		if (first_position != n + 1) {
			option = min(option, curr + tree.prod(0, first_position));
		}
		
		if (pos[co].empty()) return option;
		first_position = pos[co].back();
		pos[co].pop_back();
		curr += tree.prod(0, first_position);
		tree.set(first_position, 0);
	}
	
	return option;
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		cout << solve(test) << "\n";
	}
}