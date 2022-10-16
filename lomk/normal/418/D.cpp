/*input
27
7 9
7 26
26 11
7 16
16 10
11 1
10 27
11 13
7 8
27 24
7 4
24 19
13 21
11 14
1 20
13 15
15 17
11 18
8 5
26 23
16 3
20 12
21 6
17 25
25 2
16 22
1
7 9
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
void print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
const int N = 1e5 + 5;
using ll = long long;

struct Query {
	int id;
	pair<int, int> seg;
	Query(int _1, pair<int, int> _2): id(_1), seg(_2) {};
};

int par[18][N], depth[N], sta[N], en[N], child[N];
int ansQuery[N];
bool done[N];
vector<int> a[N];
int n, Time = 0;
vector<Query> query[N];

const int INF = 1e9;
class ITrangeMaxMin {
private:
#define mid ((l+r)/2)
	int n, f[4 * N];
	void init(int k, int l, int r) {
		f[k] = -INF; if (l == r) return;
		init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
	}
	void update(int k, int l, int r, int pos, int val) {
		if (l == r) {
			f[k] = val; return;
		}
		if (pos <= mid) update(k * 2, l, mid, pos, val);
		else update(k * 2 + 1, mid + 1, r, pos, val);
		f[k] = max(f[k * 2], f[k * 2 + 1]);
	}
	int get(int k, int l, int r, int L, int R) {
		if (r < L || R < l) return -INF;
		if (L <= l && r <= R) return f[k];
		return max(get(k * 2, l, mid, L, R), get(k * 2 + 1, mid + 1, r, L, R));
	}
public:
	void init(int _n) {n = _n; init(1, 0, n + 1);}
	int get(int l, int r) {return ((l > r) ? -INF : get(1, 0, n + 1, l, r));};
	void update(int pos, int val) {update(1, 0, n + 1, pos, val);};
#undef mid
} IT;

void pdfs(int u, int p) {
	par[0][u] = p; sta[u] = ++Time;
	for (auto v : a[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			pdfs(v, u);
		}
	}
	en[u] = Time;
}

void dfsCen(int u, int p) {
	child[u] = 1;
	for (auto v : a[u]) {
		if (v != p && !done[v]) {
			dfsCen(v, u);
			child[u] += child[v];
		}
	}
}

int lca(int p, int q) {
	if (depth[p] < depth[q]) swap(p, q);
	rloop(i, 17, 0) {
		if (depth[par[i][p]] >= depth[q])
			p = par[i][p];
	}
	if (p == q) return p;
	rloop(i, 17, 0) {
		if (par[i][p] != par[i][q])
			p = par[i][p], q = par[i][q];
	}
	return par[0][p];
}

int jump(int p, int d) {
	loop(i, 0, 17) if (bit(d, i)) p = par[i][p];
	return p;
}

void makelca() {
	pdfs(1, 1);
	loop(i, 1, 17) {
		loop(j, 1, n) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}

void prepQuery(int u, int v, int id) {
	if (depth[u] < depth[v]) swap(u, v);
	int p = lca(u, v); int d = depth[u] - depth[p] + depth[v] - depth[p];
	auto jumpTow = [&](int u, int d, int v) {
		int dx = depth[u] - depth[p] + depth[v] - depth[p];
		if (d < depth[u] - depth[p]) return jump(u, d);
		else return jump(v, dx - d);
	};
	auto sep = jumpTow(u, d / 2, v);
	if (v != p && sep == p) sep = jumpTow(u, d / 2 - 1, v);
	query[u].push_back({id, {sta[sep], en[sep]}});
	if (1 <= sta[sep] - 1)
		query[v].push_back({id, {1, sta[sep] - 1}});
	if (en[sep] + 1 <= n)
		query[v].push_back({id, {en[sep] + 1, n}});
}

int findCen(int u) {
	dfsCen(u, u);
	int sz = child[u];
	while (true) {
up: 	for (auto v : a[u]) {
			if (child[v] < child[u] && child[v] * 2 > sz) {
				u = v; goto up;
			}
		}
		return u;
	}
}

void dfsMod(int u, int p, int d, int type) {
	for (auto v : a[u]) {
		if (v == p || done[v]) continue;
		dfsMod(v, u, d + 1, type);
	}
	if (type == 1) IT.update(sta[u], d);
	else IT.update(sta[u], -INF);
}

void handleQuery(int u, int d) {
	if (query[u].empty()) return;
	for (auto cur : query[u]) {
		auto &ret = ansQuery[cur.id];
		ret = max(ret, IT.get(cur.seg.fi, cur.seg.se) + d);
	}
}

void dfsSolve(int u, int p, int d) {
	for (auto v : a[u]) {
		if (v == p || done[v]) continue;
		dfsSolve(v, u, d + 1);
	}
	handleQuery(u, d);
}

void solve(int u) {
	u = findCen(u);

	dfsMod(u, u, 0, 1);
	handleQuery(u, 0);
	for (auto v : a[u]) {
		if (done[v]) continue;
		dfsMod(v, u, 1, -1);
		dfsSolve(v, u, 1);
		dfsMod(v, u, 1, 1);
	}
	dfsMod(u, u, u, -1);

	done[u] = true;
	for (auto v : a[u]) {
		if (!done[v]) solve(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	loop(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	makelca(); IT.init(n);
	int q; cin >> q;
	loop(Q, 0, q - 1) {
		int u, v; cin >> u >> v;
		prepQuery(u, v, Q);
	}
	solve(1);
	loop(i, 0, q - 1) cout << ansQuery[i] << endl;
}