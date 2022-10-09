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
const LL INF = 2e18;
const int maxn = 400100;
const int LOG = 19;

int wyn_skok[LOG][maxn]; //skoki wynikowe
ll sum[LOG][maxn]; //skoki 

int skok[LOG][maxn];
ll max_weight[LOG][maxn];
ll weight[maxn];

int main() {
	boost;
	rep(j, 0, LOG) sum[j][1] = INF, skok[j][1] = 1;
	weight[0] = INF;
	
	int nodes = 1;
	ll last = 0;
	int zap;
	cin >> zap;
	while (zap--) {
		int type;
		cin >> type;
		if (type == 1) {
			ll R, W;
			cin >> R >> W;
			R ^= last; W ^= last;
			debug("add", R, W);
			++nodes;
			weight[nodes] = W;
			
			skok[0][nodes] = R;
			max_weight[0][nodes] = weight[R];
			int i = nodes;
			rep(j, 1, LOG) {
				int gdzie = skok[j-1][i];
				skok[j][i] = skok[j-1][gdzie];
				max_weight[j][i] = max(max_weight[j-1][gdzie], max_weight[j-1][i]);
			}
			
			//musze znalezc pierwszego wiekszego
			int x = nodes;
			for (int j=LOG-1; j>=0; --j) {
				if (max_weight[j][x] < weight[nodes]) x = skok[j][x];
			}
			
			int parent = skok[0][x];
			debug(parent);
			
			if (weight[parent] >= weight[i]) wyn_skok[0][i] = parent;
			else wyn_skok[0][i] = 0;
			sum[0][i] = weight[wyn_skok[0][i]];

			rep(j, 1, LOG) {
				int gdzie = wyn_skok[j-1][i];
				wyn_skok[j][i] = wyn_skok[j-1][gdzie];
				sum[j][i] = sum[j-1][i] + sum[j-1][gdzie];
			}
		}
		else {
			ll R, X;
			cin >> R >> X;
			R ^= last;
			X ^= last;
			debug("query", R, X);
			if (weight[R] > X) last = 0;
			else {
				X -= weight[R];
				last = 1;
				int i = R;
				for (int j=LOG-1; j>=0; --j) {
					if (sum[j][i] <= X) {
						last += (1 << j);
						X -= sum[j][i];
						i = wyn_skok[j][i];
					}
				}
			}
			cout << last << "\n";
		}
	}
}