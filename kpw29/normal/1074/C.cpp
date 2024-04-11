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

vector <PII> lines;
int best[maxn];
int x[maxn], y[maxn];

int main() {
	boost;
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> x[i] >> y[i];
	vector <PPI> xs;
	FOR(i, 1, n) {
		xs.pb({{x[i], y[i]}, i});
	}
	
	sort(all(xs));
	vector <int> magic;
	magic.pb(xs[0].e2); magic.pb(xs[n-1].e2);
	
	vector <PPI> ys;
	FOR(i, 1, n) {
		ys.pb({{y[i], x[i]}, i});
	}
	sort(all(ys));
	
	magic.pb(ys[0].e2); magic.pb(ys[n-1].e2);
	
	int sajz = sz(magic);
	for (int mask=1; mask<(1<<sajz); ++mask) {
		set <int> tot;
		int xmax = -inf, ymax = -inf;
		int xmin = inf, ymin = inf;
		
		for (int j=0; j<sajz; ++j) {
			if (mask & (1 << j)) {
				tot.insert(magic[j]);
				
				int i = magic[j];
				xmin = min(x[i], xmin);
				xmax = max(x[i], xmax);
				ymin = min(y[i], ymin);
				ymax = max(y[i], ymax);
			}
		}
		
		int ile = sz(tot);
		int score =  xmax - xmin + ymax - ymin;
		best[max(ile, 3)] = max(best[max(ile, 3)], score);
		debug(ile, score);
	}
	
	FOR(X, 1, n) {
		for (int k1 = 0; k1 < sajz; ++k1) {
			for (int k2 = k1 + 1; k2 < sajz; ++k2) {
				set <int> tot;
				int xmax = -inf, ymax = -inf;
				int xmin = inf, ymin = inf;
				auto put = [&](int i) -> void {
					xmin = min(x[i], xmin);
					xmax = max(x[i], xmax);
					ymin = min(y[i], ymin);
					ymax = max(y[i], ymax);
					tot.insert(i);
				};
				
				put(magic[k1]);
				put(magic[k2]);
				put(X);
				
				int ile = sz(tot);
				int score =  xmax - xmin + ymax - ymin;
				best[max(ile, 3)] = max(best[max(ile, 3)], score);
			}
		}
	}
	
	int res = 0;
	FOR(i, 3, n) {
		res = max(res, best[i]);
		cout << 2 * res << ' ';
	}
	
	
	
}