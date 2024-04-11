#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
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
typedef vector <ll> vll;

const LL INF = 1e18;
const int maxn = 400100;
int spo, n, k;

vi v[maxn];
vector <bool> odw;
vector <int> dist;
vector <int> par;
vector <bool> on_path;
int f[maxn];
vector <int> path;
int dist_path[maxn];

int PATHLEN;

void initdfs(int x) {
	odw[x] = 1;
	for (auto u : v[x]) {
		if (!odw[u]) {
			par[u] = x;
			dist[u] = dist[x] + 1;
			initdfs(u);
		}
	}
}

void setup() {
	odw.clear(); dist.clear(); par.clear();
	odw.resize(n+1, 0);
	dist.resize(n+1, 0);
	par.resize(n+1, 0);
}

inline int find(int x) {
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}

inline void lacz(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	--spo;
	f[x] = y;
}

vector <int> stos;

void dfs(int x, int pos_root) {
	stos.pb(x);
	odw[x] = 1;
	
	if (!on_path[x]) {
		int i = stos.size() - 1;
		if (i - k >= 0) {
			lacz(stos[i], stos[i - k]);
		}
		else {
			int di = k;
			di -= dist[x];
			if (pos_root - di >= 0) {
				lacz(stos[i], path[pos_root - di]);
			}
			if (pos_root + di < (int)path.size()) {
				lacz(stos[i], path[pos_root + di]);
			}
			
			int d1 = dist[x] + pos_root;
			int d2 = dist[x] + sz(path) - pos_root - 1;
			
			if (d1 >= d2) {
				lacz(stos[i], path[pos_root + dist[x]]);
			}
			else {
				lacz(stos[i], path[pos_root - dist[x]]);
			}
		}
	}
	
	for (auto u : v[x]) {
		if (!odw[u] && !on_path[u]) {
			dist[u] = dist[x] + 1;
			dfs(u, pos_root);
		}
	}
	
	stos.pop_back();
}

int seen[maxn];
int colors[maxn];
/*map <int, int> M[200001];

int checkdfs(int x) {
	int result = inf;
	odw[x] = 1;
	M[x][colors[x]] = dist[x];
	for (auto u : v[x]) {
		if (!odw[u]) {
			dist[u] = dist[x] + 1;
			result = min(result, checkdfs(u));
			debug(x, result);
			// move child to son
			if (M[u].size() > M[x].size()) M[x].swap(M[u]);
			trav(elem, M[u]) {
				if (M[x].find(elem.e1) != M[x].end()) { //this element already exists
					result = min(result, elem.e2 + M[x][elem.e1] - 2 * dist[x]);
				}
			}
			trav(elem, M[u]) {
				if (M[x].find(elem.e1) != M[x].end()) { //this element already exists
					M[x][elem.e1] = min(M[x][elem.e1], elem.e2);
				}
				else {
					M[x][elem.e1] = elem.e2;
				}
				
			}
		}
	}
	return result;
}*/

int gold[maxn];
int sz[maxn];
int maxsub[maxn];

void prep(int x, vector <int> &nodes) {
	odw[x] = 1;
	nodes.pb(x);
	sz[x] = 1;
	for (auto u : v[x]) {
		if (!gold[u] && !odw[u]) {
			prep(u, nodes);
			sz[x] += sz[u];
			maxsub[x] = max(maxsub[x], sz[u]);
		}
	}
}

ll weight[maxn];
ll SUM;
ll hasz[maxn];
int depth[maxn];
bool ist[maxn];
ll MAX[maxn];
ll MIN[maxn];

bool ansdfs(int x, vector <int> &vec) {
	bool ans = true;
	stos.pb(x);
	odw[x] = 1;
	vec.pb(x);
	hasz[x] = hasz[par[x]] + weight[colors[x]];
	depth[x] = 1 + depth[par[x]];
	
	if (depth[x] >= k) {
		ll tmp = hasz[x] - hasz[stos[depth[x] - k]];
		if (tmp != SUM) ans = false;
	}
	else if (depth[x] == k-1) {
		if (hasz[x] != SUM) ans = false;
	}
	else { //depth is smaller, check with other subtree
		int search_for = k - depth[x] - 1;
		if (ist[search_for]) {
			if (MAX[search_for] + hasz[x] - hasz[stos[0]] != SUM) ans = false;
			if (MIN[search_for] + hasz[x] - hasz[stos[0]] != SUM) ans = false;
		}
	}
	
	
	for (auto u : v[x]) {
		if (!gold[u] && !odw[u]) {
			par[u] = x;
			ans &= ansdfs(u, vec);
		}
	}
	
	stos.pop_back();
	return ans;
}

bool find_answers(int root) {
	hasz[root] = weight[colors[root]];
	depth[root] = 0;
	bool all_ok = true;
	stos.clear();
	stos.pb(root);
	for (auto nei : v[root]) {
		if (!gold[nei]) {
			par[nei] = root;
			vector <int> child;
			all_ok &= ansdfs(nei, child);
			trav(node, child) {
				int dp = depth[node];
				if (ist[dp]) {
					MAX[dp] = max(MAX[dp], hasz[node]);
					MIN[dp] = min(MIN[dp], hasz[node]);
				}
				else {
					ist[dp] = 1;
					MAX[dp] = hasz[node];
					MIN[dp] = hasz[node];
				}
			}
		}
	}
	
	stos.clear();
	return all_ok;
}

bool cd(int x) {
	vector <int> component;
	prep(x, component);
	int N = sz(component);
	int cen = -1;
	trav(node, component) {
		maxsub[node] = max(maxsub[node], N - sz[node]);
		if (maxsub[node] <= N / 2) cen = node;
		odw[node] = 0; sz[node] = 0; maxsub[node] = 0;
	}
	
	assert(cen != -1);
	
	// we found a centroid now
	gold[cen] = 1;
	bool ans = find_answers(cen);
	trav(node, component) {
		odw[node] = 0; sz[node] = 0; maxsub[node] = 0;
		ist[depth[node]] = 0;
	}
	
	for (auto u : v[cen]) {
		if (!gold[u]) {
			ans &= cd(u);
		}
	}
	
	return ans;
}
ll WAGA = 1e12;

bool check() {
	setup();
	FOR(i, 1, k) {
		weight[i] = ((ll)rand() * rand() + WAGA) % WAGA;
		SUM += weight[i];
	}
	
	return cd(1);
}

int A[maxn];
void solve() {
	cin >> n >> k;
	spo = n+k;
	FOR(i, 1, n+k) f[i] = i;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		A[i] = a;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	on_path.resize(n+1, 0);
	setup();
	
	initdfs(1);
	int best = 1;
	FOR(i, 2, n) if (dist[i] > dist[best]) best = i;
	int x = best;
	
	setup();
	initdfs(best);
	best = 1;
	FOR(i, 2, n) if (dist[i] > dist[best]) best = i;
	
	int y = best;
	int gdzie = y;
	on_path[gdzie] = 1;
	path = {y};
	dist_path[y] = dist[y];
	
	while (gdzie != x) {
		gdzie = par[gdzie];
		dist_path[gdzie] = dist[gdzie];
		on_path[gdzie] = 1;
		path.pb(gdzie);
	}
	
	reverse(all(path));
	debug(path);
	setup();
	
	for (int i=0; i<sz(path); ++i) {
		int jaki_kolor = i % k;
		lacz(path[i], n + 1 + jaki_kolor);
	}
	
	for (int i=0; i<sz(path); ++i) {
		dfs(path[i], i);
	}

	if (spo < k) OUT("No");
	int COL = 0;
	FOR(i, 1, n) {
		int cc = find(i);
		if (!seen[cc]) {
			if (COL < k) ++COL;
			seen[cc] = COL;
		}
		colors[i] = seen[cc];
	}
	
	if (check()) {
		cout << "Yes\n";
		FOR(i, 1, n) {
			cout << colors[i] << ' ';
		}
		
		cout << endl;
	}
	else {
		cout << "No\n";
	}
	
	
}

int main() {
	srand(2137);
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}