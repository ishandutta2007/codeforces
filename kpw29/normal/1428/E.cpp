#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

const int maxn = 100100;

ll n, k;
ll tab[maxn];

inline ll sq(ll x) {
	return x * x;
}

inline ll f(ll ile, ll czesci) {
	assert(czesci > 0);
	ll kazdy = (ile / czesci);
	ll reszta = (ile - kazdy * czesci);
	
	return (czesci - reszta) * sq(kazdy) + reszta * sq(kazdy + 1);
}

int current[maxn];
set <PLL> deltas;

void solveone() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> tab[i];
	ll wynik = 0;
	
	FOR(i, 1, n) {
		current[i] = 1;
		deltas.insert({f(tab[i], current[i] + 1) - f(tab[i], current[i]), i});
	}
	
	int re = k - n;
	for (int step = 0; step < re; ++step) {
		PLL best_delta = *(deltas.begin());
		deltas.erase(deltas.begin());
		
		int i = best_delta.e2;
		current[i]++;
		deltas.insert({f(tab[i], current[i] + 1) - f(tab[i], current[i]), i});
	}
	
	FOR(i, 1, n) wynik += f(tab[i], current[i]);
	cout << wynik << endl;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	solveone();
}