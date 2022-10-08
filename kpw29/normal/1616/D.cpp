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
const ll INF = 1e12;

int brut(vector<ll> vec) {
	int n = sz(vec) - 1;
	int all = (1 << n);
	
	int small = n;
	for (int mask= 0; mask < all; ++mask) {
		vector <ll> liczby(n);
		rep(i, 0, n) liczby[i] = vec[i + 1];
		rep(i, 0, n) {
			if (mask & (1 << i)) {
				liczby[i] = INF;
			}
		}
		
		bool ok = true;
		rep(i, 0, n) {
			ll ile = liczby[i];
			rep(j, i+1, n) {
				ile += liczby[j];
				if (ile < 0) ok = false;
			}
		}
			
		if (ok) small = min(small, __builtin_popcount(mask));
	}
	
	return n - small;
}

bool TEST = 0;

void solve(int tc) {
	int n;
	if (!TEST) cin >> n;
	else n = random(5, 10);
	vector<ll> vec(n + 1);
	if (!TEST) FOR(i, 1, n) cin >> vec[i];
	else FOR(i, 1, n) vec[i] = random(-10, 10);
	int x;
	if (!TEST) cin >> x;
	else x = random(-10, 10);
	FOR(i, 1, n) vec[i] -= x;
	
	int cnt = 0;
	ll temp = 0;
	int zlych = 0;
	int lastbad = -1;
	
	FOR(i, 1, n) {
		temp += vec[i];
		if (cnt == 0) {
		}
		else {
			if (temp < 0) {
				cnt = 0;
				temp = 0;
				lastbad = i;
				zlych++;
			}
		}
		if (cnt != 0) {
			temp = min(temp, vec[i]);
		}
		if (lastbad != i) ++cnt;
		else cnt = 0;
	}
	
	int wynik = n - zlych;
	if (TEST) {
		auto br = brut(vec);
		if (br != wynik) {
			debug(n, x);
			debug(vec);
			debug(br);
			debug(wynik);
			OUT("WA");
		}
	}
	
	cout << n - zlych << "\n";
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