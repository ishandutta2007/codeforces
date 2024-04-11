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
mt19937_64 rng(time(0));
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
const int mod = 1e9+7;

inline ll potmod(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	
	return res;
}

ll fac[2 * maxn], ifac[2 * maxn];

inline ll dwumian(int n, int k) {
	if (n < 0) return 0;
	return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}

inline ll takeK(int k, int n) {
	if (k < 0) return 0;
	if (n < 0) return 0;
	
	int zabranych = k - 1;
	n -= zabranych;
	if (n < 0) return 0;
	return dwumian(n, k);
}

int main() {
	boost;
	fac[0] = 1; ifac[0] = 1;
	int n;
	cin >> n;
	int N = 2 * n;
	FOR(i, 1, N) fac[i] = fac[i-1] * i % mod;
	ifac[N] = potmod(fac[N], mod - 2);
	for (int i=N-1; i>0; --i) {
		ifac[i] = ifac[i+1] * (i + 1) % mod;
	}
	
	//FOR(i, 0, N) debug(fac[i], ifac[i]);
	ll result = 0;
	int wolnych = (n - 1) % 2;
	for (int k=0; k<=(n+1)/2; ++k) {
		if (k % 2 == wolnych) continue;
		// consider two options, either digit taken or not
		
		// used before
		ll zostanie = n-1 - k;
		ll nailespos = takeK(k, n-1);
		if (zostanie >= 0) result += nailespos * fac[zostanie];
		result %= mod;
	}
	
	debug(result);
	result = result * (2 * n) % mod;
	cout << result << endl;
}