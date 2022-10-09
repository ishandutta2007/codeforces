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
mt19937_64 rng(0);
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


const int maxn = 500100;


int a, b, n, m;
vector <int> v[maxn];
int pre[maxn], low[maxn], TIME, sz[maxn];
int parent[maxn];

int which_subtree[maxn];
bool odw[maxn];

void dfs(int x, int par, int wxd) {
	odw[x] = true;
	pre[x] = ++TIME;
	low[x] = pre[x];
	sz[x] = 1;
	if (par == a) wxd = x;
	which_subtree[x] = wxd;
	parent[x] = par;
	
	for (auto u : v[x]) {
		if (!odw[u]) {
			dfs(u, x, wxd);
			low[x] = min(low[x], low[u]);
			sz[x] += sz[u];
		}
		else {
			low[x] = min(low[x], pre[u]);
		}
	}
	
}

void solveone() {
	TIME = 0;
	cin >> n >> m >> a >> b;
	FOR(i, 1, n) {
		v[i].clear();
		odw[i] = false;
	}
	
	FOR(i, 1, m) {
		int p, q;
		cin >> p >> q;
		v[p].pb(q);
		v[q].pb(p);
	}
	
	dfs(a, -1, -1);
	ll jedne = 0, drugie = 0;
	FOR(i, 1, n) {
		if (a == i || b == i) continue;
		if (which_subtree[i] != which_subtree[b]) ++jedne;
	}
	
	
	FOR(i, 1, n) {
		if (a == i || b == i) continue;
		if (parent[i] == b) {
			if (low[i] == pre[b]) drugie += sz[i];
		}
	}
	
	cout << jedne * drugie << "\n";
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}