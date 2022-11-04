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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, LG = 18, mod = 1000000007;
int n, p[MX][LG], lvl[MX], q;
ll d[MX], d2[MX], sz[MX], sd[MX], sd2[MX], tor[MX];
vii adj[MX];

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	forn (j, LG)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[u][j];

	if (u == v) return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}

	return p[u][0];
}

void pre (int u) {
	sz[u] = 1;

	for (ii &v : adj[u])
		if (v.fi != p[u][0]) {
			lvl[v.fi] = lvl[u] + 1;
			p[v.fi][0] = u;
			tor[v.fi] = (tor[u] + v.se) % mod;

			pre(v.fi);

			sz[u] += sz[v.fi];
			(sd[u] += (sd[v.fi] + sz[v.fi] * v.se)) %= mod;
			(sd2[u] += (sd2[v.fi] + 2 * sd[v.fi] * v.se + v.se * v.se % mod * sz[v.fi])) %= mod;
		}
}

void dfs (int u) {
	for (ii &v : adj[u])
		if (v.fi != p[u][0]) {
			d[v.fi] = (d[u] + v.se * (n - 2 * sz[v.fi])) % mod;
			d2[v.fi] = (d2[u] + 2 * v.se * (d[u] - 2 * (sd[v.fi] + v.se * sz[v.fi]) % mod) % mod + v.se * v.se % mod * n) % mod;
			dfs(v.fi);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	p[1][0] = 1;
	pre(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];

	d[1] = sd[1];
	d2[1] = sd2[1];
	dfs(1);

	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;

		int lca = LCA(u, v);
		ll res = lca == v ? d2[u] : -d2[u];
		ll dis = (tor[u] + tor[v] - 2 * tor[lca]) % mod;

		if (lca == v) {
			(res -= 2 * (
				((d2[v] - sd2[v]) + 2 * (d[v] - sd[v]) * dis + dis * dis % mod * (n - sz[v])) % mod
			)) %= mod;
		} else {
			(res += 2 * (
				(sd2[v] + 2 * sd[v] * dis + dis * dis % mod * sz[v]) % mod
			)) %= mod;
		}

		cout << MOD(res, mod) << endl;
	}

	return 0;
}