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

int n, m;

int calc(vi &st, vi &target) {
	vector <bool> odw(n+1, false);
	vi perm(n + 1, 0);
	vi gdzie(n + 1, 0);
	FOR(i, 1, n) gdzie[target[i]] = i;
	FOR(i, 1, n) perm[i] = gdzie[st[i]];
	
	int cycles = 0;
	FOR(i, 1, n) {
		if (!odw[i]) {
			++cycles;
			int j = i;
			while (!odw[j]) {
				odw[j] = 1;
				j = perm[j];
			}
		}
	}
	
	return n - cycles;
}

void check(vector <int> &perm, vector <bool> &poss, int is_correct) {
	int co = perm[is_correct];
	int initial_pos = co;
	int new_pos = is_correct;
	
	int k = (new_pos - initial_pos + 2 * n) % n;
	vector <int> option(n + 1, 0);
	int DL = 0;
	int last = n - k;
	FOR(i, 1, k) option[++DL] = last + i;
	FOR(i, 1, n-k) option[++DL] = i;
	
	debug(k, option);
	
	if (calc(option, perm) <= m) poss[k] = 1;
}

void solve() {
	cin >> n >> m;
	vi p(n+1);
	p[0] = 0;
	
	rep(i, 1, n+1) {
		cin >> p[i];
	}
	
	vector <bool> poss(n, 0);
	
	vector <int> tries(n);
	rep(i, 0, n) {
		tries[i] = i;
	}
	
	random_shuffle(all(tries));
	int TR = min(n, 300);
	rep(tr, 0, TR) {
		check(p, poss, tr + 1);
	}
	
	
	int cnt = 0;
	rep(i, 0, n) {
		if (poss[i]) ++cnt;
	}
	cout << cnt << ' ';
	rep(i, 0, n) {
		if (poss[i]) cout << i << ' ';
	}
	
	cout << "\n";
}

int main() {
	srand(2137);
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}