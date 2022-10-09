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

int n, zap;
int ans[maxn];
vector <int> primes[maxn];

vector <int> pr;
int f[maxn];

inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

bool lacz(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 1;
	f[x] = y;
	return 0;
}

int A[maxn], B[maxn];
int jest[maxn];
unordered_set <ll> connections;

void conn(int i, int j) {
	if (i > j) swap(i, j);
	connections.insert((ll)i * maxn + j);
}

int tab[maxn];

int main() {
	boost;
	rep(i, 2, maxn) {
		if (primes[i].empty()) {
			for (int j=i; j<maxn; j+=i) primes[j].pb(i);
		}
	}
	rep(i, 1, maxn) f[i] = i;
	
	cin >> n >> zap;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		tab[i] = a;
		jest[a] = 1;
		trav(prim, primes[a]) {
			lacz(prim, a);
		}
	}
	
	// ok spojne zlaczone
	
	FOR(i, 1, zap) {
		ans[i] = 2;
		cin >> A[i] >> B[i];
		A[i] = tab[A[i]];
		B[i] = tab[B[i]];
		if (find(A[i]) == find(B[i])) {
			ans[i] = 0;
		}
	}
	
	// 0s checked, now search 1s
	rep(i, 2, maxn) {
		for (int j = i; j < maxn; j+=i) {
			if (jest[j - 1]) {
				trav(u, primes[j]) {
					conn(find(j - 1), find(u));
				}
				for (int a = 0; a < sz(primes[j]); ++a) {
					for (int b = a + 1; b < sz(primes[j]); ++b) {
						conn(find(primes[j][a]), find(primes[j][b]));
					}
				}
			}
		}
	}
	
	FOR(i, 1, zap) {
		if (ans[i] == 2) {
			int q1 = find(A[i]), q2 = find(B[i]);
			if (q1 > q2) swap(q1, q2);
			if (q1 == q2 || connections.find((ll)maxn * q1 + q2) != connections.end()) ans[i] = 1;
		}
		
		cout << ans[i] << "\n";
	}
}