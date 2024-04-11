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
typedef vector <pii> vpi;


void solve(int tc) {
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	
	int maks = -1, id = -1;
	vector <bool> res(n, 0);
	
	rep(i, 0, n) {
		if (a[i] > maks) {
			maks = a[i];
			id = i;
		}
	}
	debug(id);
	vector <pii> taba(n);
	rep(i, 0, n) taba[i] = {a[i], i};
	vector <pii> tabb(n);
	rep(i, 0, n) tabb[i] = {b[i], i};
	sort(all(taba));
	sort(all(tabb));
	
	pii comp = {a[id], b[id]};
	res[id] = 1;
	
	int i = n - 1, j = n - 1;
	while (true) {
		bool flag = false;
		if (i >= 0 && taba[i].e1 > comp.e1) {
			int ktory = taba[i].e2;
			res[ktory] = 1;
			--i;
			flag = true;
			comp.e1 = min(comp.e1, a[ktory]);
			comp.e2 = min(comp.e2, b[ktory]);
		}
		if (j >= 0 && tabb[j].e1 > comp.e2) {
			int ktory = tabb[i].e2;
			res[ktory] = 1;
			--j;
			flag = true;
			comp.e1 = min(comp.e1, a[ktory]);
			comp.e2 = min(comp.e2, b[ktory]);
		}
		
		if (!flag) break;
	}
	
	rep(step, 0, n) cout << res[step];
	cout << "\n";
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