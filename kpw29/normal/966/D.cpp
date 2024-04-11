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
const int maxn = 500100;

int n, m;
bool considered[maxn];

vi ans;
bool odw[maxn];
int par[maxn];
int d[maxn];
vi v[maxn];
vi init;

void bfs(int st, vi &cc) {
	queue <int> q;
	q.push(st);
	d[st] = 0; par[st] = 0; odw[st] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cc.pb(x);
		
		for (auto u : v[x]) {
			if (!odw[u] && considered[u]) {
				q.push(u);
				odw[u] = 1;
				par[u] = x;
				d[u] = d[x] + 1;
			}
		}	
	}
}

bool is_edge(int x, int y) {
	return binary_search(all(v[x]), y);
}

void odp(vi &vec) {
	if (!init.empty() && sz(init) < sz(vec)) vec = init;
	
	cout << sz(vec) - 1 << endl;
	trav(u, vec) cout << u << ' ';
	exit(0);
}

int main() {
	boost;
	cin >> n >> m;
	FOR(i, 1, n) considered[i] = 1;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) sort(all(v[i]));
	vi dummy;
	bfs(1, dummy);
	if (par[n] != 0) { //no loops whatsoever
		int x = n;
		while (x != 1) {
			ans.pb(x);
			x = par[x];
		}
		ans.pb(1);
		reverse(all(ans));
		init = ans;
		ans.clear();
	}
	if (!init.empty() && sz(init) <= 5) {
		cout << sz(init) - 1 << endl;
		trav(u, init) cout << u << ' ';
		exit(0);
	}
	
	FOR(i, 2, n) {
		if (odw[i] && !is_edge(1, i)) { //first case - 1 a y 1 n
			while (par[i] && !is_edge(1, par[i])) i = par[i];
			ans.pb(1);
			bool flag = false;
			for (int c = 2; c <= n; ++c) {
				if (i == c) continue;
				if (is_edge(1, c) && is_edge(i, c)) {
					ans.pb(c);
					flag = 1;
					break;
				}
			}
			ans.pb(i);
			ans.pb(1);
			ans.pb(n);
			
			odp(ans);
		}
	}
	
	// third case - split CCs and find one missing // 1 x a y 1 n
	if (!init.empty() && sz(init) <= 6) {
		cout << sz(init) - 1 << endl;
		trav(u, init) cout << u << ' ';
		exit(0);
	}
	
	FOR(i, 1, n) {
		considered[i] = 0;
		if (odw[i]) considered[i] = 1;
		
		odw[i] = 0;
		d[i] = 0;
		par[i] = 0;
	}
	
	considered[1] = 0;
	odw[1] = 1;
	FOR(i, 2, n) {
		if (considered[i] && !odw[i]) {
			vi comp;
			bfs(i, comp);
			
			int roz = sz(comp);
			for (int b=0; b<roz; ++b) {
				for (int a=0; a<b; ++a) {
					if (!is_edge(comp[a], comp[b])) { //last positive answer, let's retrieve it
						int x = comp[a], y = comp[b];
						ans.pb(1);
						ans.pb(x);
						
						bool flag = false;
						for (int c = 0; c < roz; ++c) {
							if (a == c) continue;
							if (b == c) continue;
							if (is_edge(comp[a], comp[c]) && is_edge(comp[b], comp[c])) {
								ans.pb(comp[c]);
								flag = 1;
								break;
							}
						}
						
						assert(flag);
						ans.pb(y);
						ans.pb(x);
						// now we returned to first node, so go to N
						ans.pb(n);
						odp(ans);
					}
				}
			}
		}
	}
	
	if (!init.empty()) {
		cout << sz(init) - 1 << endl;
		trav(u, init) cout << u << ' ';
	}
	else {
		cout << -1;
	}
}