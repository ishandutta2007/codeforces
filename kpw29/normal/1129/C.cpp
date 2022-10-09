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

/*namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger gout(FG_GREEN);
ColorDebugger rout(FG_RED);*/

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
const int maxn = 3010;
int tab[maxn];

int dp[maxn][maxn];
const int mod = 1e9+7;

int res[maxn];

void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}
const ll P = 7;

ll HASH_MOD = 1e9+7;
ll HASH_MOD_2 = 1e9+696969;
ll POT[maxn];
ll POT_2[maxn];

void solve() {
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> tab[i];
	}
	
	FOR(i, 1, n) {
		vi ciag;
		dp[i][i-1] = 1;
		FOR(j, i, n) {
			ciag.pb(tab[j]);
			int sz = ciag.size();
			int co = 0;
			for (int k=1; k<=4; ++k) {
				if (sz - k < 0) break;
				co += (ciag[sz - k] << (k-1));
				if (k < 4 || (k == 4 && co != 3 && co != 5 && co != 14 && co != 15)) addmod(dp[i][j], dp[i][j - k]);
			}
		}
	}
	
	POT[0] = 1;
	FOR(i, 1, n) POT[i] = POT[i-1] * P % HASH_MOD;
	POT_2[0] = 1;
	FOR(i, 1, n) POT_2[i] = POT_2[i-1] * P % HASH_MOD_2;
	
	FOR(k, 1, n) {
		unordered_set<ll> secik;
		ll hasz1 = 0, hasz2 = 0;
		
		FOR(i, 1, n-k+1) {
			int j = i + k - 1;
			if (i == 1) {
				FOR(st, 1, k) {
					hasz1 = (hasz1 * P + tab[st]) % HASH_MOD;
					hasz2 = (hasz2 * P + tab[st]) % HASH_MOD_2;
				}
			}
			else {
				ll delt = POT[k - 1] * tab[i - 1] % HASH_MOD;
				hasz1 = (hasz1 - delt + HASH_MOD) % HASH_MOD;
				
				ll delt_2 = POT_2[k - 1] * tab[i - 1] % HASH_MOD_2;
				hasz2 = (hasz2 - delt_2 + HASH_MOD_2) % HASH_MOD_2;
				
				// teraz dodajemy
				hasz1 = (hasz1 * P + tab[j]) % HASH_MOD;
				hasz2 = (hasz2 * P + tab[j]) % HASH_MOD_2;
			}
			
			//debug(i, j, hasz1, hasz2);
			if (secik.find(hasz1 * HASH_MOD + hasz2) == secik.end()) {
				debug("Is free", i, j, dp[i][j]);
				addmod(res[j], dp[i][j]);
				secik.insert(hasz1 * HASH_MOD + hasz2);
			}
		}
	}
	
	FOR(i, 1, n) {
		addmod(res[i], res[i-1]);
		cout << res[i] << "\n";
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