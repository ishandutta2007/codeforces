#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

const int MX = 100005, LMX = 18;
int n, m, u, v, uv, p[MX][LMX], lvl[MX], q;
ll w[MX][LMX], d[MX][50], flo[50][50];
vi o;
vii adj[MX], gra[MX];
bitset<MX> bs;

void dfs (int u) {
	bs[u] = 1;

	for (ii &v : adj[u]) {
		if (v.fi == p[u][0]) continue;

		if (!bs[v.fi]) {
			p[v.fi][0] = u;
			w[v.fi][0] = v.se;
			lvl[v.fi] = lvl[u] + 1;

			dfs(v.fi);
		} else {
			gra[u].emplace_back(v.fi, v.se);
			gra[v.fi].emplace_back(u, v.se);
			o.pb(u), o.pb(v.fi);
		}
	}
}

ll dist (int u, int v) {
	ll res = 0;
	if (lvl[u] < lvl[v]) swap(u, v);
	
	for (int j = LMX-1; j >= 0; j--)
		if ((lvl[u] - lvl[v]) & (1 << j)) {
			res += w[u][j];
			u = p[u][j];
		}

	if (u == v) return res;

	for (int j = LMX-1; j >= 0; j--)
		if (p[u][j] != p[v][j]) {
			res += w[u][j] + w[v][j];
			u = p[u][j];
			v = p[v][j];
		}

	res += w[u][0] + w[v][0];
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		cin >> u >> v >> uv;
		adj[u].emplace_back(v, uv);
		adj[v].emplace_back(u, uv);
	}

	p[1][0] = 1;
	dfs(1);

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j-1]][j-1];
			w[i][j] = w[i][j-1] + w[p[i][j-1]][j-1];
		}

	sort(ALL(o));
	o.erase(unique(ALL(o)), o.end());

	m = o.size();

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = dist(i, o[j]);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			flo[i][j] = d[o[i]][j];

		for (ii &j : gra[o[i]]) {
			v = find(o, j.fi);
			flo[i][v] = min(flo[i][v], (ll)j.se);
		}
	}

	for (int k = 0; k < m; k++)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				flo[i][j] = min(flo[i][j], flo[i][k] + flo[k][j]);

	cin >> q;
	while (q--) {
		cin >> u >> v;

		ll res = dist(u, v);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				res = min(res, d[u][i] + flo[i][j] + d[v][j]);
		
		cout << res << endl;
	}

	return 0;
}