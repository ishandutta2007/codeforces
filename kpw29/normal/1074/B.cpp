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
const int maxn = 1000100;
bool mark[maxn];
vector <int> jego;
bool odw[maxn];
int KEY;
vi v[maxn];

int ask(char guy, int node) {
	cout << guy << ' ' << node << endl;
	int as;
	if (guy != 'C') cin >> as;
	return as;
}

void dfs(int x) {
	odw[x] = 1;
	if (KEY == -1 && mark[x]) KEY = x;
	for (auto u : v[x]) {
		if (!odw[u]) dfs(u);
	}
}

void solve() {
	int n;
	cin >> n;
	FOR(i, 1, n) v[i].clear(), mark[i] = false, odw[i] = 0;
	KEY = -1;
	
	jego.clear();
	
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	int k1, k2;
	cin >> k1;
	FOR(i, 1, k1) {
		int a;
		cin >> a;
		mark[a] = 1;
	}
	
	cin >> k2;
	FOR(i, 1, k2) {
		int a ;
		cin >> a;
		jego.pb(a);
	}
	
	sort(all(jego));
	int my_node = ask('B', jego[0]);
	if (mark[my_node]) {
		ask('C', my_node);
		return;
	}
	
	dfs(my_node);
	assert(KEY != -1);
	
	int other_node = ask('A', KEY);
	if (binary_search(all(jego), other_node)) {
		ask('C', KEY);
	}
	else {
		ask('C', -1);
	}
}

int main() {
	boost;
	int tests;
	cin >> tests;
	FOR(z, 1, tests) {
		solve();
	}
}