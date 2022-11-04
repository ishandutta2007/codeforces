#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005, LMX = 19;

// --- DSU ---
int par[MX], rk[MX], anc[MX];
ll co[MX];

void init () {
	for (int i = 0; i < MX; i++) {
		par[i] = i;
		rk[i] = 0;
	}
}

int parent (int a) {
	return a == par[a] ? a : par[a] = parent(par[a]);
}

void joint (int a, int b) { // a parent of b
	a = parent(a), b = parent(b);

	if (rk[a] > rk[b]) {
		par[b] = a;
	} else {
		co[b] = co[a];
		anc[b] = anc[a];
		par[a] = b;
		if (rk[a] == rk[b])
			rk[b]++;
	}
}

ll obtCost (int a) {
	return co[parent(a)];
}

int obtAnc (int a) {
	return parent(anc[parent(a)]);
}
// --- --- ---

int n, m;
int u[MX], v[MX], lvl[MX], p[LMX][MX];
ll w[MX];
vi adj[MX];
int op, a, b, ind;
ll y, c;

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

void preLCA () {
	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j-1][p[j-1][i]];
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v])
		swap(u, v);

	for (int j = LMX - 1; j >= 0; j--)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];

	if (u == v)
		return u;

	for (int j = LMX - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u];
}

stack<ll> st;
ll obtRes () {
	int lca = LCA(a, b);
	a = parent(a), b = parent(b), lca = parent(lca);

	if (a == b)
		return y;

	while (y && a != lca) {
		y /= obtCost(a);
		a = obtAnc(a);
	}

	if (!y)
		return 0;

	while (st.size())
		st.pop();

	for (int i = 0; b != lca && i <= 62; i++) {
		if (i == 62)
			return 0;

		st.push(obtCost(b));
		b = obtAnc(b);
	}

	while (y && st.size()) {
		y /= st.top();
		st.pop();
	}

	return y;
}

void update () {
	a = u[ind], b = v[ind];
	if (parent(a) == parent(b))
		return;

	if (c == 1) {
		joint(a, b);
	} else {
		co[parent(b)] = c;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	init();

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}

	p[0][1] = 1;
	lvl[1] = 0;
	dfs(1);
	preLCA();

	for (int i = 1; i < n; i++) {
		if (lvl[u[i]] > lvl[v[i]])
			swap(u[i], v[i]);
		co[v[i]] = w[i];
		anc[v[i]] = u[i];
	}

	for (int i = 1; i < n; i++)
		if (w[i] == 1)
			joint(u[i], v[i]);

	while (m--) {
		cin >> op;

		if (op == 1) {
			cin >> a >> b >> y;
			cout << obtRes() << endl;
		} else {
			cin >> ind >> c;
			update(); 
		}
	}

	return 0;
}