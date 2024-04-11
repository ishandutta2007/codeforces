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

//Did you REAALLY consider sample tests?

vi f;
vi sz;
int comps;

int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

void lacz(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	f[x] = y;
	sz[y] += sz[x];
}

void solve(int tc) {
	int n, m;
	cin >> n >> m;
	vi A(m), B(m);
	rep(i, 0, m) cin >> A[i] >> B[i];
	rep(i, 0, m) {
		f.clear();
		f.resize(n+1, 0);
		sz.clear();
		sz.resize(n+1, 1);
		rep(j, 1, n+1) f[j] = j;
		
		FOR(j, 0, i) {
			lacz(A[j], B[j]);
		}
		
		vi sizes;
		int sp = 0;
		FOR(node, 1, n) {
			if (find(node) == node) {
				++sp;
				debug(node);
				sizes.pb(sz[node]);
			}
		}
		
		int need_edges = 0;
		debug(sizes);
		trav(u, sizes) need_edges += u - 1;
		
		int remain = i + 1 - need_edges;
		assert(remain >= 0);
		sort(all(sizes), greater<int>());
		
		int wynik = 0;
		remain = min(remain, sz(sizes) - 1);
		FOR(j, 0, remain) wynik += sizes[j];
		
		cout << wynik - 1 << "\n";
	}
	
	
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