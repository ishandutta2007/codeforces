#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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

namespace Color {
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
ColorDebugger rout(FG_RED);

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

bool LOCAL = 0;

int ask(int root, vector <int> v1, vi v2) {
	if (v1.empty() || v2.empty()) return 0;
	cout << sz(v1) << "\n";
	trav(node, v1) cout << node << ' ';
	cout << "\n";
	cout << sz(v2) << "\n";
	trav(node, v2) cout << node << ' ';
	cout << "\n" << root << endl;
	
	if (LOCAL) {
	}
	else {
		int ans;
		cin >> ans;
		return ans;
	}
}

int par[510];

int main() {
	int n;
	cin >> n;
	vector <int> nodes = {};
	vector <PII> tab;
	vi noti = {};
	FOR(j, 2, n) {
		noti.pb(j);
	}
		
	FOR(i, 2, n) {
		tab.pb({ask(i, noti, {1}), i});
	}
	
	sort(all(tab));
	
	auto check = [&](int ro, int x, int y) -> bool {
		vector <int> zb;
		FOR(it, x, y) zb.pb(nodes[it]);
		return ask(ro, {1}, zb) > 0;
		
	};
	
	rep(step, 0, n-1) {
		int v = tab[step].e2;
		
		int k = ask(v, nodes, {1});
		
		for (int _ = 1; _ <= k; ++_) {
			int x = 0, y = sz(nodes) - 1;
			while (x < y) {
				int sr = ((x + y) >> 1) + 1;
				if (!check(v, sr, y)) y = --sr;
				else x = sr;
			}
		
			par[nodes[x]] = v;
			nodes.erase(nodes.begin() + x);
		}
		
		nodes.pb(v);
	}
	
	trav(u, nodes) par[u] = 1;
	cout << "ANSWER" << endl;
	FOR(i, 2, n) cout << i << ' ' << par[i] << "\n";
	cout << endl;
	
}