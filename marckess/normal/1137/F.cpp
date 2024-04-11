#include <bits/stdc++.h>

//#define endl '\n'
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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;

int ft[2*MX];
void update (int i, int k) { for (; i < 2 * MX; i += i & -i) ft[i] += k; }
int query (int i) { int s = 0; for (; i; i -= i & -i) s += ft[i]; return s; }

int p[MX][18], lvl[MX];
int lca (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	for (int i = 17; i + 1; i--) if ((lvl[u] - lvl[v]) & (1 << i)) u = p[u][i];
	if (u == v) return u;
	for (int i = 17; i + 1; i--) if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
	return p[u][0];
}

int n, q, f[MX], pt[MX], c[MX], fin[2*MX], sz[MX], cn = 0, last;
vi adj[MX];
set<int> st[MX];

void dfs (int u, int p) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
}

void pre (int u, int ch, int par) {
	f[u] = ++cn;
	pt[cn] = ch;
	st[ch].insert(cn);
	if (cn == ch) st[ch].insert(ch-1);

	int mx = 0, ind;
	for (int v : adj[u])
		if (v != par && sz[v] > mx)
			mx = sz[v], ind = v;

	if (mx) {
		p[cn+1][0] = f[u];
		lvl[cn+1] = lvl[f[u]] + 1;
		pre(ind, ch, u);
	}

	for (int v : adj[u])
		if (v != par && v != ind) {
			p[cn+1][0] = f[u];
			lvl[cn+1] = lvl[f[u]] + 1;
			pre(v, cn+1, u);
		}
}

void init () {
	priority_queue<int, vi, greater<int>> pq;
	int d[MX];

	for (int i = 1; i <= n; i++) {
		d[i] = adj[i].size();
		if (d[i] == 1) pq.push(i);
	}

	cn = 0;
	while (pq.size()) {
		int u = pq.top();
		pq.pop();

		c[f[u]] = ++cn;
		fin[cn] = f[u];
		update(cn, 1);

		for (int v : adj[u]) {
			d[v]--;
			if (d[v] == 1) pq.push(v);
		}
	}

	last = f[n];
}

void update (int u) {
	int v = last;
	fin[++cn] = last;
	update(cn, lvl[u] + lvl[v] - 2 * lvl[lca(u, v)] + 1);
	last = u;

	while (pt[u] != pt[v]) {
		if (lvl[pt[u]] < lvl[pt[v]]) swap(u, v);

		auto it = st[pt[u]].lower_bound(u);
		while (it != st[pt[u]].begin()) {
			auto ant = it;
			ant--;
			if (u < *it) update(c[*it], -(u - *ant));
			else {
				update(c[*it], -(*it - *ant));
				st[pt[u]].erase(it);
			}
			it = ant;
		}

		st[pt[u]].insert(u);
		c[u] = cn;
		u = p[pt[u]][0];
	}

	if (lvl[u] > lvl[v]) swap(u, v);

	auto it = st[pt[v]].lower_bound(v);

	while (it != st[pt[u]].begin()) {
		auto ant = it;
		ant--;
		if (*ant < u) break;
		if (v < *it) update(c[*it], -(v - *ant));
		else {
			update(c[*it], -(*it - *ant));
			st[pt[u]].erase(it);
		}
		it = ant;
	}

	auto ant = it;
	ant--;
	if (*ant < u - 1) {
		st[pt[u]].insert(u - 1);
		c[u - 1] = c[*it];
		if (v < *it) update(c[*it], -(v - u + 1));
		else {
			update(c[*it], -(*it - u + 1));
			st[pt[u]].erase(it);
		}
	} else {
		if (v < *it) update(c[*it], -(v - *ant));
		else {
			update(c[*it], -(*it - *ant));
			st[pt[u]].erase(it);
		}
	}

	st[pt[u]].insert(v);
	c[v] = cn;
}

int when (int u) {
	int col = c[*st[pt[u]].lower_bound(u)];
	return query(col-1) + lvl[u] + lvl[fin[col]] - 2 * lvl[lca(u, fin[col])] + 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}	

	dfs(1, -1);
	p[1][0] = 1;
	pre(1, 1, -1);

	for (int j = 1; j < 18; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];

	init();
	while (q--) {
		string s;
		int x, y;

		cin >> s >> x;
		if (s == "up") update(f[x]);
		else if (s == "when") cout << when(f[x]) << endl;
		else {
			cin >> y;
			if (when(f[x]) < when(f[y])) cout << x << endl;
			else cout << y << endl;
		}
	}

	//cout << query(8) - query(7) << endl;
	//cout << query(9) - query(8) << endl;
	//cout << query(10) - query(9) << endl;

	return 0;
}