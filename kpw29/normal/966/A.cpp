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

void solve() {
	
}

ll suf(ll a, ll b) {
	if (a % b == 0) return a / b;
	return 1 + a / b;
}

int main() {
	boost;
	
	int floors, sections, stair, elev, speed;
	cin >> floors >> sections >> stair >> elev >> speed;
	
	vector <ll> stairs(stair);
	rep(i, 0, stair) cin >> stairs[i];
	
	vector <ll> elevs(elev);
	rep(i, 0, elev) cin >> elevs[i];
	
	int tests;
	//tests = 1;
	cin >> tests;
	vector <ll> ans(tests, INF);
	
	rep(test, 0, tests) {
		int h1, x1, h2, x2;
		cin >> h1 >> x1 >> h2 >> x2;
		if (h1 == h2) {
			ans[test] = abs(x1 - x2);
			continue;
		}
		
		if (!stairs.empty()) {
			auto it = lower_bound(all(stairs), x1);
			if (it != stairs.end()) {
				ll d1 = abs(*it - x1);
				ll d2 = abs(*it - x2);
				ans[test] = min(ans[test], d1 + d2 + abs(h1 - h2));
			}
			
			if (it != stairs.begin()) {
				--it;
				ll d1 = abs(*it - x1);
				ll d2 = abs(*it - x2);
				ans[test] = min(ans[test], d1 + d2 + abs(h1 - h2));
			}
		}
		
		if (!elevs.empty()) {
			auto it = lower_bound(all(elevs), x1);
			if (it != elevs.end()) {
				ll d1 = abs(*it - x1);
				ll d2 = abs(*it - x2);
				ans[test] = min(ans[test], d1 + d2 + suf(abs(h1 - h2), speed));
			}
			if (it != elevs.begin()) {
				--it;
				ll d1 = abs(*it - x1);
				ll d2 = abs(*it - x2);
				ans[test] = min(ans[test], d1 + d2 + suf(abs(h1 - h2), speed));
			}
		}
	}
	
	trav(c, ans) cout << c << "\n";
}