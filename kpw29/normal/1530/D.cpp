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
int n;
void solve() {
	cin >> n;
	
	vector <int> zajety, tab;
	vector <int> res(n + 1, 0);
	
	zajety.resize(n + 1, 0);
	tab.resize(n + 1, 0);
	int wyn = 0;
	
	FOR(i, 1, n) cin >> tab[i];
	vector <int> rem;
	
	FOR(i, 1, n) {
		int kom = tab[i];
		if (!zajety[kom]) {
			zajety[kom] = 1;
			res[i] = kom;
			++wyn;
		}
		else {
			rem.pb(i);
		}
	}
	
	deque <int> wstawiam;
	FOR(i, 1, n) {
		if (!zajety[i]) wstawiam.push_back(i);
	}
	
	int sz = rem.size();
	assert((int)wstawiam.size() == sz);
	
	FOR(i, 1, n) {
		if (res[i] == 0) {
			bool ok = false;
			int opt = wstawiam.front();
			if (opt != i && !ok) {
				ok = true;
				wstawiam.pop_front();
				res[i] = opt;
			}
			
			if (!ok) {
				opt = wstawiam.back();
				if (opt != i) {
					ok = true;
					res[i] = opt;
					wstawiam.pop_back();
				}
			}
			
			if (!ok) {
				assert(wstawiam.size() == 1);
				assert(wstawiam.front() == i);			
				FOR(j, 1, n) {
					if (j != i && tab[i] == tab[j]) {
						res[i] = res[j];
						res[j] = i;
						ok = true;
						break;
					}
				}
				
				assert(ok);
			}
		}
	}

	cout << wyn << "\n";
	FOR(i, 1, n) cout << res[i] << ' ';
	cout << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}