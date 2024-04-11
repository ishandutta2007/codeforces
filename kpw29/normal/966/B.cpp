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

int n;
ll s[2];
ll best[2];
ll curr[2];

int gdzie[2];
bool marked[maxn];
vector <int> ans[2];

int main() {
	boost;
	cin >> n >> s[0] >> s[1];
	vector <PII> tab(n);
	rep(i, 0, n) {
		cin >> tab[i].e1;
		tab[i].e2 = i + 1;
	}
	
	sort(all(tab));
	best[0] = best[1] = INF;
	
	for (int i=n-1; i>=0; --i) {
		ll myval = tab[i].e1;
		rep(server, 0, 2) {
			ll needs = s[server] / myval;
			while (myval * needs < s[server]) ++needs;
			curr[server] = needs;
			
			int total = n - i;
			if (best[server ^ 1] + needs <= total) { //ans
				int start = gdzie[server ^ 1];
				debug(start);
				debug(tab);
				for (int jemu = 0; jemu < best[server ^ 1]; ++jemu) {
					ans[server ^ 1].pb(tab[start + jemu].e2);
					marked[start + jemu] = 1;
				}
				
				for (int mi = i; mi < n; ++mi) {
					if (!marked[mi]) ans[server].pb(tab[mi].e2);
				}
				
				cout << "Yes\n";
				cout << sz(ans[0]) << ' ' << sz(ans[1]) << "\n";
				trav(u, ans[0]) cout << u << ' ';
				cout << endl;
				trav(u, ans[1]) cout << u << ' ';
				exit(0);
			}
		}
		
		rep(server, 0, 2) {
			int current = n - i;
			if (curr[server] > current) continue;
			
			if (curr[server] < best[server]) {
				gdzie[server] = i;
				best[server] = curr[server];
			}
		}
		
	}
	
	cout << "No\n";
}