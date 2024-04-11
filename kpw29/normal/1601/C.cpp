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
#include <bits/extc++.h>
using namespace __gnu_pbds;
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*1LL)+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const {
		return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
template<class K,class V> V get(ht<K,V>& u, K x) {
	auto it = u.find(x); return it == end(u) ? 0 : it->s; }
	

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

//Did you REAALLY consider sample tests?

int n, m;
vi a, b;
pii res[maxn];
int stan[20];

struct FT {
	vector<int> s;
	void init(int range) {
		s.resize(range);
	}
	void clear() { s.clear(); }
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int rest = 0;
		for (; pos > 0; pos &= pos - 1) rest += s[pos-1];
		return rest;
	}
};
FT trees[20];
FT global;

struct DP { // Modify at will:
	int lo(int ind) { return 0; }
	int hi(int ind) { return n+1; } //mam miejsca od [0..n]
	int f(int ind, int k, int lvl) { //liczymy liczbe inwersji
		while (stan[lvl] < k) {
			trees[lvl].update(a[stan[lvl]], 1);
			stan[lvl]++;
		}
		
		int liczba = b[ind];
		int lewo_inv = k - trees[lvl].query(liczba + 1);
		int prawo_inv = global.query(liczba) - trees[lvl].query(liczba);
		
		return lewo_inv + prawo_inv;
	}
	void store(int ind, int k, ll v) { res[ind] = pll(k, v); }

	void rec(int L, int R, int LO, int HI, int lvl) {
		if (L >= R) return;
		int mid = (L + R) >> 1;
		pii best(INT_MAX, LO);
		rep(k, max(LO,lo(mid)), min(HI,hi(mid)))
			best = min(best, make_pair(f(mid, k, lvl), k));
		store(mid, best.second, best.first);
		rec(L, mid, LO, best.second+1, lvl + 1);
		rec(mid+1, R, best.second, HI, lvl + 1);
	}
	void solve(int L, int R) { rec(L, R, INT_MIN, INT_MAX, 0); }
};

void solve(int tc) {
	rep(i, 0, 20) trees[i].clear();
	cin >> n >> m;
	//n = 1000000; m = 1000000;
	rep(i, 0, 20) stan[i] = 0, trees[i].init(n+m+1);
	
	a.clear(); a.resize(n); b.clear(); b.resize(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	//rep(i, 0, n) a[i] = rand()%(int)1e9+1;
	//rep(i, 0, m) b[i] = rand()%(int)1e9+1;
	
	vi skal(n+m);
	rep(i, 0, n) skal[i] = a[i];
	rep(i, 0, m) skal[n+i] = b[i];
	sort(all(skal));
	ht <int, int> M;
	M[skal[0]] = 1;
	int cnt = 1;
	rep(i, 1, sz(skal)) {
		if (skal[i] == skal[i-1]);
		else {
			++cnt;
			M[skal[i]] = cnt;
		}
	}
	
	rep(i, 0, n) a[i] = M[a[i]];
	rep(i, 0, m) b[i] = M[b[i]];
	
	rep(i, 0, n) assert(a[i] <= n + m);
	rep(i, 0, m) assert(b[i] <= n + m);
	debug(a);
	debug(b);
	
	global.clear();
	
	ll opt = 0;
	global.init(n+m+1);
	for (int i=n-1; i>=0; --i) {
		opt += global.query(a[i]);
		global.update(a[i], 1);
	}
	
	sort(all(b));
	rep(i, 0, n) res[i] = {0, 0};
	DP solver;
	solver.solve(0, m);
	
	rep(i, 0, m) opt += res[i].e2;
	cout << opt << "\n";	
}

int main() {
	boost;
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}