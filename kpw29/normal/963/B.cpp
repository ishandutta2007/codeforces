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
const int maxn = 200100;
bool odw[maxn];
int par[maxn];
vi v[maxn], ch[maxn];
vi pre;
int deg[maxn];
bool rem[maxn];
int REM = 0;
int n;

vi wyn;

void dfs(int x) {
	pre.pb(x);
	for (auto u : ch[x]) {
		dfs(u);
	}
	
	if (deg[x] % 2 == 0 && !rem[x]) {
		vector <int> re;
		while (pre.back() != x) {
			re.pb(pre.back());
			pre.pop_back();
		}
		re.pb(pre.back());
		pre.pop_back();
		debug(x, re);
		
		reverse(all(re));
		trav(node, re) {
			wyn.pb(node);
			assert(!rem[node]);
			rem[node] = 1;
			assert(deg[node] % 2 == 0);
			trav(nei, v[node]) {
				deg[nei]--;
				deg[node]--;
			}
		}
		
	}
		
}

void solve() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> par[i];
		if (par[i] != 0) {
			ch[par[i]].pb(i);
			deg[par[i]]++;
			deg[i]++;
			
			
			v[par[i]].pb(i);
			v[i].pb(par[i]);
		}
	}
	
	FOR(i, 1, n) {
		if (par[i] == 0) dfs(i);
	}
	
	if (sz(wyn) == n) {
		cout << "YES\n";
		trav(node, wyn) cout << node << "\n";
	}
	else {
		cout << "NO\n";
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