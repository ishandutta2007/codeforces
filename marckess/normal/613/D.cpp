#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1e5+5, LMX = 18;

struct S {
	int u, v, lca, lvl;
	S () {}
	S (int u, int v, int lca, int lvl) : u(u), v(v), lca(lca), lvl(lvl) {}
	bool operator < (const S &ot) const {
		return lvl < ot.lvl;
	}
};

int n, q, u, v, k, p[MX][LMX], ini[MX], fin[MX], lvl[MX], cn = 0;
int inv[2*MX];
vi adj[MX];
priority_queue<S> pq;
set<int> ex, res;

void dfs (int u) {
	ini[u] = ++cn;
	inv[cn] = u;

	for (int v : adj[u])
		if (!ini[v]) {
			p[v][0] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}

	fin[u] = ++cn;
	inv[cn] = u;
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	int aux = u;

	for (int j = LMX - 1; j >= 0; j--)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[u][j];

	if (u == v) {
		u = aux;
		for (int j = LMX - 1; j >= 0; j--)
			if (lvl[u] - lvl[v] - 1 & (1 << j))
				u = p[u][j];
		return u;
	}

	for (int j = LMX - 1; j >= 0; j--)
		if (p[u][j] != p[v][j])
			u = p[u][j], v = p[v][j];

	return p[u][0];
}

void insert (int u, int v) {
	if (inv[u] == inv[v])
		return;

	int lca = LCA(inv[u], inv[v]);
	pq.emplace(inv[u], inv[v], lca, lvl[lca]);
}

void solve () {
	ex.clear(), res.clear();

	cin >> k;
	while (k--) {
		cin >> u;
		ex.insert(ini[u]);
		ex.insert(fin[u]);
	}

	for (int u : ex)
		if (inv[u] != 1 && ex.count(ini[p[inv[u]][0]])) {
			cout << -1 << endl;
			return;
		}

	u = -1;
	for (int v : ex) {
		if (u != -1) insert(u, v);
		u = v;
	}

	while (pq.size()) {
		S ac = pq.top(); pq.pop();

		if (!ex.count(ini[ac.u]) || !ex.count(ini[ac.v]))
			continue;

		res.insert(ac.lca);

		auto it = ex.lower_bound(ini[ac.lca]);
		auto jt = ex.upper_bound(fin[ac.lca]);
		jt--;

		if (it != ex.begin()) {
			auto a = it, b = jt;
			a--, b++;

			if (b != ex.end())
				insert(*a, *b);
		}

		while (1) {
			if (it == jt) {
				ex.erase(it);
				break;
			} else {
				auto aux = it;
				it++;
				ex.erase(aux);
			}
		}
	}

	cout << res.size() << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	p[1][0] = 1;
	dfs(1);

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];

	cin >> q;
	while (q--)
		solve();

	return 0;
}