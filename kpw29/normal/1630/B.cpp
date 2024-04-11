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
int len(pii x) {
	return x.e2 - x.e1;
}

pii cmp(pii a, pii b) {
	if (len(a) < len(b)) return a;
	return b;
}

bool in_range(pii a, int x) {
	return a.e1 <= x && x <= a.e2;
}

//Did you REAALLY consider sample tests?
void solve(int tc) {
	int n, k;
	cin >> n >> k;
	vi arr(n+1);
	FOR(i, 1, n) cin >> arr[i];
	vector<pii> tab(n);
	rep(i, 0, n) tab[i] = {arr[i+1], i+1};
	sort(all(tab));
	
	pii min_range = {0, maxn};
	rep(i, 0, n) {
		int dwax = n + k;
		int x = (dwax + 1) / 2;
		int j = i + x - 1;
		debug(x, i, j);
		if (j >= n) continue;
		pii option = {tab[i].e1, tab[j].e1};
		debug(option);
		
		min_range = cmp(min_range, option);
	}
	
	debug(min_range);
	cout << min_range.e1 << ' ' << min_range.e2 << "\n";
	vector <pii> vec;
	int start = 1, cnt = 0;
	FOR(i, 1, n) {
		if (in_range(min_range, arr[i])) ++cnt;
		else --cnt;
		if (cnt > 0 && sz(vec) + 1 < k) {
			vec.pb({start, i});
			cnt = 0;
			start = i + 1;
		}
	}
	
	if (sz(vec) < k) vec.pb({start, n});
	
	for (auto u : vec) cout << u.e1 << ' ' << u.e2 << "\n";
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