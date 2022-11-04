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

int n, m, a, b, p[75], s[75], f[75], cn, u, v, dis[75][1<<18], adj[75][75];
queue<int> qa, qb;
queue<int> ma, mb;
queue<int> da, db;

int parent (int a) { return a == p[a] ? a : p[a] = parent(p[a]); }
bool same (int a, int b) { return parent(a) == parent(b); }
void join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;
	p[b] = a;
	s[a] += s[b];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dis, -1, sizeof(dis));
	iota(p, p+75, 0);
	fill(s, s+75, 1);
	
	cin >> n >> m >> a >> b;

	while (m--) {
		cin >> u >> v;
		cin >> adj[u][v];
		adj[v][u] = adj[u][v];
		if (adj[u][v] == a) join(u, v);
	}

	for (int i = 1; i <= n; i++)
		if (p[i] == i && s[i] > 3)
			f[i] = cn++;

	qa.push(1);
	da.push(0);
	if (s[parent(1)] > 3) {
		dis[1][1<<f[p[1]]] = 0;
		ma.push(1<<f[p[1]]);
	} else {
		dis[1][0] = 0;
		ma.push(0);
	}

	while (qa.size() || qb.size()) {
		int u, mk, d;

		if (qa.size() && (qb.empty() || da.front() <= db.front())) {
			u = qa.front(), mk = ma.front(), d = da.front();
			qa.pop(), ma.pop(), da.pop();
		} else {
			u = qb.front(), mk = mb.front(), d = db.front();
			qb.pop(), mb.pop(), db.pop();
		}

		if (d > dis[u][mk]) continue;

		for (int v = 1; v <= n; v++) {
			if (!adj[u][v]) continue;
			if (same(u, v)) { if (adj[u][v] == b) continue; }
			else if (s[p[v]] > 3 && (mk & (1 << f[p[v]]))) continue;
			int aux = mk;
			if (s[p[v]] > 3) aux |= (1 << f[p[v]]);
			if (dis[v][aux] == -1 || dis[v][aux] > d + adj[u][v]) {
				dis[v][aux] = d + adj[u][v];
				if (adj[u][v] == a) {
					qa.push(v);
					ma.push(aux);
					da.push(dis[v][aux]);
				} else {
					qb.push(v);
					mb.push(aux);
					db.push(dis[v][aux]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int res = -1;
		for (int j = 0; j < (1 << cn); j++)
			if (dis[i][j] != -1 && (res == -1 || res > dis[i][j]))
				res = dis[i][j];
		cout << res << " ";
	}
	cout << endl;

	return 0;
}