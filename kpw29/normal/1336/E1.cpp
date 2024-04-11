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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;

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

const int maxn = 1010000;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m, k;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}

vector <ll> pots[40];

int clz(unsigned long long N) {
    return N ? 63 - __builtin_clzll(N) : 0;
}

ll tab[40];

int dp[20][(1 << 17)];
int ndp[20][(1 << 17)];
ll res[40];

int main() {
	boost;
	cin >> n >> m;
	ll zeros = 0;
	FOR(i, 1, n) {
		ll val;
		cin >> val;
		if (val == 0) ++zeros;
		else {
			int x = clz(val);
			pots[x].push_back(val);
		}
	}
	
	for (int bit = 38; bit >= 0; --bit) {
		if (pots[bit].size() > 1) {
			for (int j = 1; j < (int)pots[bit].size(); ++j) {
				ll new_value = (pots[bit][0] ^ pots[bit][j]);
				if (new_value == 0) ++zeros;
				else pots[clz(new_value)].push_back(new_value);
			}
		}
	}
	
	FOR(bit, 0, 37)
		if (!pots[bit].empty()) tab[bit] = pots[bit][0];
		else tab[bit] = -1;
	
	ll sc = 1;
	FOR(i, 1, zeros) sc = sc * 2LL % mod;
	
	int pod = 17; //we keep bits from 0 to 16
	int mx = 36; //tego bitu nigdy nie bedzie
	int LEN = mx - pod;
	int PW = (1 << LEN);
	int KEY_NUMBER = (1 << 17) - 1;
	
	for (int i=0; i<PW; ++i) {
		ll ksor = 0; bool fail = false;
		for (int j=17; j<36; ++j) {
			if (i & (1 << (j - 17))) {
				if (tab[j] == -1) fail = true;
				else ksor ^= tab[j];
			}
		}
		
		if (!fail) {
			int sm = 0;
			for (int j=17; j<36; ++j)
				if (ksor & (1LL << j)) sm++;
			
			//debug(sm, ksor & KEY_NUMBER);
			dp[sm][ksor & KEY_NUMBER]++;
		}
	}
	
	
	int pt = (1 << 17);
	for (int i=0; i<17; ++i)
		if (tab[i] != -1) {
			for (int sz = 0; sz < 20; ++sz)
				for (int num = 0; num < pt; ++num) ndp[sz][num] = dp[sz][num];
			
			for (int sz = 0; sz < 20; ++sz)
				for (int num = 0; num < pt; ++num) addmod(ndp[sz][num ^ tab[i]], dp[sz][num]);
				
			for (int sz = 0; sz < 20; ++sz)
				for (int num = 0; num < pt; ++num) dp[sz][num] = ndp[sz][num];
		}

	for (int sz = 0; sz < 20; ++sz)
		for (int num = 0; num < pt; ++num)
			res[sz + __builtin_popcount(num)] += dp[sz][num];
		
	for (int i=0; i<=m; ++i) cout << res[i] * sc % mod << ' ';
}