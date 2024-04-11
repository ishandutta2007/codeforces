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
bool LOCAL = 0;

//Did you REAALLY consider sample tests?

void solve(int tc) {
	int n;
	if (!LOCAL) cin >> n;
	else n = random(2, 10);
	vi a(n + 1), b(n + 1);
	if (!LOCAL) {
		FOR(i, 1, n) cin >> a[i];
		//rep(i, 0, n) cin >> b[i];
	}
	else {
		/*rep(i, 0, n) a[i] = random(1, n);
		rep(i, 0, n) b[i] = a[i];
		random_shuffle(all(b));*/
	}
	
	debug(a, b);
	
	vector<vi> gdzie(n + 1);
	FOR(i, 1, n) gdzie[a[i]].pb(i);
	
	vi ile(n + 1);
	FOR(i, 1, n) ile[a[i]]++;
	vector<pii> vec;
	FOR(i, 1, n) {
		if (ile[i] > 0) vec.pb({ile[i], i});
	}
	
	vi ans(n + 1, -1);
	
	int poszlo = 0;
	sort(all(vec));
	for (int st = 0; st < sz(vec); ++st) {
		int teraz = vec[st].e1 - poszlo;
		if (teraz == 0) continue;
		poszlo += teraz;
		int N = sz(vec) - st;
		int DLL = 0;
		vi liczby(N * teraz);
		vi pozycje(N * teraz);
		
		for (int j = st; j < sz(vec); ++j) {
			for (int step = 0; step < teraz; ++step) {
				int co = vec[j].e2;
				assert(!gdzie[co].empty());
				pozycje[DLL] = gdzie[co].back();
				liczby[DLL] = co;
				++DLL;
				gdzie[co].pop_back();
			}
		}
		
		int SIZE = N * teraz;
		for (int i = 0; i < SIZE; ++i) {
			ans[pozycje[(i + teraz) % SIZE]] = liczby[i];
		}
	}
	
	FOR(i, 1, n) cout << ans[i] << ' ';
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