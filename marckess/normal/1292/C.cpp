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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 3005, LG = 12;
int n, sz[MX], lvl[MX], p[MX][LG];
ll mem[MX][MX];
vi adj[MX];

void dfs (int u) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p[u][0]) {
			lvl[v] = lvl[u] + 1;
			p[v][0] = u;
			dfs(v);
			sz[u] += sz[v];
		}
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	for (int i = 0; i < LG; i++)
		if ((lvl[u] - lvl[v]) & (1 << i))
			u = p[u][i];
	if (u == v) return u;
	for (int i = LG - 1; i >= 0; i--)
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	return p[u][0];
}

int anc (int u, int k) {
	for (int i = 0; i < LG; i++)
		if (k & (1 << i))
			u = p[u][i];
	return u;
}

ll dp (int i, int j) {
	if (i == j) return 0;
	if (i > j) swap(i, j);
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	res = 0;

	int lca = LCA(i, j);
	if (lca == j) swap(i, j);
	
	if (lca == i) {
		int ant = anc(j, lvl[j] - lvl[i] - 1);
		res = max(dp(i, p[j][0]), dp(ant, j)) + (n - sz[ant]) * sz[j];
	} else {
		res = max(dp(i, p[j][0]), dp(p[i][0], j)) + sz[i] * sz[j];
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
		
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	p[1][0] = 1;
	dfs(1);
	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];

	memset(mem, -1, sizeof(mem));
	ll res = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			res = max(res, dp(i, j));
	cout << res << endl;

	return 0;
}