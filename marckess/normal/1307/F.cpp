#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 400005, LG = 20;
int n, k, r, Q, x[MX], lvl[MX], p[LG][MX], from[MX], dis[MX], st[MX];
vi adj[MX];
queue<int> q;

void add (int u, int v) {
	adj[u].pb(v);
	adj[v].pb(u);
}

int parent (int a) {
	return a == st[a] ? a : st[a] = parent(st[a]);
}

void join (int a, int b) {
	st[parent(a)] = parent(b);
}

bool same (int a, int b) {
	return parent(a) == parent(b);
}

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	for (int j = 0; j < LG; j++)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[j][u];

	if (u == v) return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u];
}

int dist (int a, int b) {
	int lca = LCA(a, b);
	return lvl[a] + lvl[b] - 2 * lvl[lca];
}

int go (int a, int b) {
	int lca = LCA(a, b), t = k;

	if (lvl[a] - lvl[lca] < k) {
		t = lvl[b] - lvl[lca] - (k - (lvl[a] - lvl[lca]));
		swap(a, b);
	}

	for (int j = 0; j < LG; j++)
		if (t & (1 << j))
			a = p[j][a];

	return a;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(st, st + MX, 0);
	
	cin >> n >> k >> r;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		add(u, n + i);
		add(n + i, v);
	}

	p[0][1] = 1;
	dfs(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i < 2 * n; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];

	for (int i = 0; i < r; i++) {
		cin >> x[i];
		q.push(x[i]);
		from[x[i]] = x[i];
	}

	while (q.size()) {
		int u = q.front();
		q.pop();

		if (dis[u] >= k) continue;

		for (int v : adj[u])
			if (!from[v]) {
				from[v] = from[u];
				dis[v] = dis[u] + 1;
				q.push(v);
			} else {
				join(from[u], from[v]);
			}
	}

	cin >> Q;
	while (Q--) {
		int u, v;
		cin >> u >> v;

		if (dist(u, v) <= 2 * k) {
			cout << "YES" << endl;
		} else {
			int a = go(u, v);
			int b = go(v, u);

			if (from[a] && from[b] && same(from[a], from[b])) 
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}