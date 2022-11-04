#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2e5+5;
int n, m, u, v, o, s, sdom[MX], par[MX], dom[MX], dsu[MX], lab[MX], arr[MX], rev[MX], cnt = 1;
vii gra[MX];
vi adj[MX], tree[MX], rad[MX], buc[MX];
ll dist[MX], w;

void dfs (int u) {
	arr[u] = cnt, rev[cnt] = u, cnt++;

	for (int v : adj[u]) {
		if (!arr[v]) {
			dfs(v);
			par[arr[v]] = arr[u];
		}
		rad[arr[v]].push_back(arr[u]);
	}
}

int find (int u, int x = 0) {
	if (u == dsu[u])
		return x ? -1 : u;
    
	int v = find(dsu[u], x + 1);
	if (v < 0) return u;
    
	if (sdom[lab[dsu[u]]] < sdom[lab[u]])
		lab[u] = lab[dsu[u]];
	dsu[u] = v;

	return x ? v : lab[u];
}

void dijkstra () {
	priority_queue<ii, vii, greater<ii>> pq;

	pq.emplace(0, s);
	dist[s] = 0;

	while (pq.size()) {
		int u; ll d;
		tie(d, u) = pq.top();
		pq.pop();

		for (ii &v : gra[u])
			if (dist[v.fi] == -1 || d + v.se < dist[v.fi]) {
				dist[v.fi] = d + v.se;
				pq.emplace(dist[v.fi], v.fi);
			}
	}
}

int d2 (int u, int p) {
	int d = 1;
	for (int v : tree[u])
		if (v != p)
			d += d2(v, u);
	return d;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(sdom, sdom+MX, 0);
	iota(dsu, dsu+MX, 0);
	iota(lab, lab+MX, 0);
	memset(dist, -1, sizeof(dist));
	
	cin >> n >> m >> s;

	while (m--) {
		cin >> u >> v >> w;
		gra[u].emplace_back(v, w);
		gra[v].emplace_back(u, w);
	}

	dijkstra();

	for (int u = 1; u <= n; u++) {
		if (dist[u] == -1) continue;

		for (ii &v : gra[u])
			if (dist[u] + v.se == dist[v.fi])
				adj[u].pb(v.fi);
	}

	dfs(s);

	for (int i = cnt - 1; i >= 1; i--) {
		for (int v : rad[i]) sdom[i] = min(sdom[i], sdom[find(v)]);

		if (i > 1) buc[sdom[i]].push_back(i);

		for (int v : buc[i]) {
			int w = find(v);

			if (sdom[v] == sdom[w]) dom[v] = sdom[v];
			else dom[v] = w;
		}

		if (i > 1) dsu[i] = par[i];
	}

	for (int i = 2; i < cnt; i++) {
		if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
		tree[rev[i]].push_back(rev[dom[i]]);
		tree[rev[dom[i]]].push_back(rev[i]);
    }

	int res = 0;
	for (int v : tree[s])
		res = max(res, d2(v, s));

	cout << res << endl;

	return 0;
}