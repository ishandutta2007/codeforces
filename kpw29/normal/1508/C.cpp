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
const ll INF = (ll)1e18 + 3;
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


const int maxn = 200100;

int f[maxn];
ll n, m;
int comp[maxn];
bool odw[maxn];
set <int> tovisit;
int A[maxn], B[maxn], C[maxn];
int e[maxn];

inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

set <PII> edges;

void dfs(int x, int start) {
	odw[x] = 1;
	comp[x] = start;
	int iter = 0;
	while (true) {
		set <int>::iterator it = tovisit.upper_bound(iter);
		if (it == tovisit.end()) return;
		int u = *it;
		iter = u;
		if (edges.find(mp(x, u)) == edges.end()) {
			tovisit.erase(it);
			odw[u] = true;
			dfs(u, start);
		}
	}
}

bool cmp(int x, int y) {
	return C[x] < C[y];
}

bool special[maxn];
vector <int> v[1010];
int par[1010], dep[1010];
bool help[maxn];
int edge_value[1010];

void tree(int x) {
	help[x] = 1;
	for (auto u : v[x]) {
		if (!help[u]) {
			par[u] = x;
			dep[u] = dep[x] + 1;
			edge_value[u] = inf;
			tree(u);
		}
	}
}

void solveone() {
	cin >> n >> m;
	
	int xorall = 0;
	ll pozostalych = n * (n - 1) / 2 - m;
	
	FOR(i, 1, m) {
		cin >> A[i] >> B[i] >> C[i];
		xorall ^= C[i];
		edges.insert(make_pair(A[i], B[i]));
		edges.insert({B[i], A[i]});
	}
	
	FOR(i, 1, n) tovisit.insert(i);
	int CC = 0;
	for (int i=1; i<=n; ++i) {
		if (!odw[i]) {
			dfs(i, i);
			++CC;
		}
	}
	
	ll spanning_tree = 0;
	FOR(i, 1, m) e[i] = i;
	sort(e+1, e+m+1, cmp);
	
	FOR(i, 1, n) f[i] = comp[i]; //takie spojne sa
	FOR(step, 1, m) {
		int i = e[step];
		int a = A[i], b = B[i];
		if (find(a) != find(b)) {
			f[find(a)] = find(b);
			spanning_tree += C[i];
			special[i] = 1;
		}
	}
	
	int ile_do_drzewa = n - 1 - (CC - 1);
	
	if (pozostalych > ile_do_drzewa) { // there is some component that is not a tree
		OUT(spanning_tree); // we can make that one not count
	}
	else { // unfortunately only trees -> all bad edges are worthy
		assert(n <= 1000);
		for (int i=1; i<=n; ++i) {
			for (int j=i+1; j<=n; ++j) {
				if (edges.find(make_pair(i, j)) == edges.end()) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		
		ll res = INF;
		FOR(i, 1, m) {
			if (special[i]) {
				int a = A[i], b = B[i];
				v[a].push_back(b);
				v[b].push_back(a);
			}
		}
		
		tree(1);
		FOR(i, 1, n) f[i] = i;
		FOR(step, 1, m) {
			int i = e[step];
			if (special[i]) continue;
			int a = A[i], b = B[i];
			a = find(a); b = find(b);
			while (a != b) {
				if (dep[a] < dep[b]) swap(a, b); //moving from a upwards
				// moving by one edge
				edge_value[a] = C[i];
				assert(f[a] == a);
				f[a] = find(par[a]);
				a = f[a]; // made a jump
			}
		}
		
		// now let's gather all answers
		//FOR(i, 1, n) debug(i, par[i], edge_value[i]);
		
		FOR(i, 2, n) {
			int p = par[i];
			if (edges.find({i, p}) == edges.end()) { //this is a good edge
				res = min(res, spanning_tree + min(xorall, edge_value[i]));
			}
		}
		
		OUT(res);
	}
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}