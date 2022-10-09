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
const int maxn = 100100;
const ll INF = 1e18;
//Did you REAALLY consider sample tests?

ll sufit(ll a, ll b) {
	if (a % b == 0) return a / b;
	return 1 + a / b;
}

ll S[maxn], A[maxn], B[maxn];

ll n, s;
vector <pll> jed, dwa;

ll zabierz(ll a, ll b, vector <pll> &vec) { // zabieramy A i wsadzamy B w to miejsce
	ll brakuje = a % s; //this too many
	ll wynik = 0;
	debug(a, b, brakuje);
	debug(vec);
	
	sort(all(vec));
	rep(i, 0, sz(vec)) {
		ll ile = min(brakuje, vec[i].e2);
		brakuje -= ile;
		wynik += ile * vec[i].e1;
	}
	
	if (brakuje != 0) wynik = INF;
	
	return wynik;
}

void solve(int tc) {
	cin >> n >> s;
	ll tot = 0, a = 0, b = 0;
	rep(i, 0, n) {
		cin >> S[i] >> A[i] >> B[i];
		tot += S[i];
	}
	
	ll pizzas = sufit(tot, s);
	ll best = 0;
	rep(i, 0, n) {
		if (A[i] > B[i]) {
			a += S[i];
			best += A[i] * S[i];
			jed.pb({A[i] - B[i], S[i]});
		}
		else {
			best += B[i] * S[i];
			b += S[i];
			dwa.pb({B[i] - A[i], S[i]});
		}
	}
	debug(jed); debug(dwa);
	if (sufit(a, s) + sufit(b, s) == pizzas) OUT(best);
	// we need to make one less pizza
	ll a1 = best - zabierz(a, b, jed);
	ll a2 = best - zabierz(b, a, dwa);
	cout << max(a1, a2) << endl;
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