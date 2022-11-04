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

const int MX = 3005, LMX = 12, MQ = 400005;
int n, m, u, v, q, p[MX][LMX], lvl[MX], vis[MX], off[MX];
int s[MQ], t[MQ], k[MQ], res[MQ];
vi pos[MX], adj[MX];
bitset<MX> ex;

int dfs (int u, int l, int cyc) {
	ex[u] = !bool(cyc);
	lvl[u] = l;
	vis[u] = 1;

	for (int v : adj[u]) {
		if (vis[v] == 2) continue;
		if (vis[v] == 1) {
			cyc++;
			off[v]++;
			continue;
		}

		p[v][0] = u;
		cyc = dfs(v, l+1, cyc);
	}

	vis[u] = 2;
	cyc -= off[u];
	off[u] = 0;
	return cyc;
}

void solve (int u) {
	memset(vis, 0, sizeof(vis));
	ex.reset();

	dfs(u, 1, 0);

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];

	for (int j : pos[u]) {
		int v = t[j];

		if (!ex[v] || lvl[v] < k[j]) {
			res[j] = -1;
			continue;
		}

		k[j] = lvl[v] - k[j];

		for (int i = LMX - 1; i >= 0; i--)
			if (k[j] & (1 << i))
				v = p[v][i];

		res[j] = v;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].pb(v);
	}

	for (int i = 1; i <= n; i++) sort(ALL(adj[i]));

	for (int i = 0; i < q; i++) {
		cin >> s[i] >> t[i] >> k[i];
		pos[s[i]].pb(i);
	}

	for (int i = 1; i <= n; i++) solve(i);

	for (int i = 0; i < q; i++) cout << res[i] << endl;

	return 0;
}