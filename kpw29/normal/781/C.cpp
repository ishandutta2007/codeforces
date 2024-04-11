#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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
const int maxn = 200100;
bool odw[maxn];
vector <int> v[maxn];
bool marked[maxn];
int max_allowed;
vector <vi> paths;
vi path;

void consider(int x) {
	debug("cons", x);
	if (!path.empty() || !marked[x]) {
		path.pb(x);
		marked[x] = 1;
	}
	if (sz(path) == max_allowed) {
		paths.pb(path);
		path.clear();
	}
}

void dfs(int x) {
	odw[x] = 1;
	consider(x);
	
	for (auto u : v[x]) {
		if (!odw[u]) {
			dfs(u);
			consider(x);
		}
	}
}

void solve(int tc) {
	//Did you REAALLY consider sample tests?
	int n, m, k;
	cin >> n >> m >> k;
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	max_allowed = 2 * n / k;
	if (k * max_allowed < 2 * n) ++max_allowed;
	
	dfs(1);
	if (!path.empty()) paths.pb(path);
	int wyn = sz(paths);
	assert(wyn <= k);
	
	trav(vec, paths) {
		cout << sz(vec) << ' ';
		trav(node, vec) cout << node << ' ';
		cout << "\n";
	}
	
	FOR(i, 1, k - wyn) cout << "1 1\n";
	
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}