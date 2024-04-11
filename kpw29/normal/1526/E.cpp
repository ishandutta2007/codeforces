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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
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
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 1000100;
const int mod = 998244353;
inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

ll fac[maxn+1], ifac[maxn+1];

ll binom(ll n, ll k) {
	return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector <ll> v(n, 0);
	vector <ll> pos(n+1, 0);
	
	fac[0] = 1; ifac[0] = 1;
	FOR(i, 1, maxn) fac[i] = (ll)i * fac[i-1] % mod;
	ifac[maxn] = potmod(fac[maxn], mod - 2);
	for (int i=maxn-1; i>0; --i) {
		ifac[i] = ifac[i+1] * (i + 1) % mod;
	}

	FOR(i, 0, n-1) {
		cin >> v[i];
		pos[v[i]] = i;
	}
	pos[n] = -1;
	vector <char> example(n, 'a');
	
	int used = 1;
	for (int i = 1; i < n; ++i) {
		int poprz = v[i - 1], ten = v[i];
		if (pos[poprz + 1] > pos[ten + 1]){ //niewlasciwy order, ++k
			++used;
		}
		example[ten] = 'a' + used - 1;
	}

	if (used > k) cout << "0\n";
	else {
		int skokow = k - used;
		cout << binom(n + skokow, skokow) << endl;
	}
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}