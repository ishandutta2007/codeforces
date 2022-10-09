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
void solve(int tc) {
	int n;
	cin >> n;
	//n = random(1, 10) * 2 + 1;
	vi perm(n + 1);
	vi wynik;
	bool ans = true;
	FOR(i, 1, n) {
		cin >> perm[i];
	}
	
	//random_shuffle(perm.begin()+1, perm.begin()+n+1);
	
	FOR(i, 1, n) {
		if (perm[i] % 2 != i % 2) ans = false;
	}
	
	if (!ans) TCOUT(-1);
	// else possible
	auto search = [&](int value) -> int{
		FOR(i, 1, n) {
			if (perm[i] == value) return i;
		}
	};
	
	auto odwroc = [&](int prefix) {
		wynik.pb(prefix);
		reverse(perm.begin()+1, perm.begin()+prefix+1);
	};
	
	for (int odd = n; odd > 1; odd -= 2) {
		int even = odd - 1;
		int gdzie = search(odd);
		odwroc(gdzie);
		
		gdzie = search(even);
		odwroc(gdzie - 1); //now they are next to each other
		odwroc(gdzie + 1); //now they are in positions [2,3]
		odwroc(3);
		odwroc(odd);
	}
	
	FOR(i, 1, n) assert(perm[i] == i);
	cout << sz(wynik) << "\n";
	assert(sz(wynik) <= (5 * n / 2));
	trav(node, wynik) cout << node << ' ';
	cout << "\n";
}

int main() {
	int tests;
	cin >> tests;
	//tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}