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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 2005, LG = 12;
int n, m, p[LG][MX], x[2][MX], lca[2][MX][MX], lvl[2][MX], mn[MX], res;
int mem[MX][MX][2];
vi adj[MX];

void dfs (int u, int f) {
	if (!adj[u].size()) return;

	mn[u] = 1e9;
	for (int v : adj[u]) {
		lvl[f][v] = lvl[f][u] + 1;
		dfs(v, f);
		mn[u] = min(mn[u], mn[v]);
	}

	sort(all(adj[u]), [&] (int i, int j) {
		return mn[i] < mn[j];
	});
}

int LCA (int u, int v, int f) {
	if (lvl[f][u] < lvl[f][v])
		swap(u, v);

	for (int j = LG - 1; j >= 0; j--)
		if (lvl[f][u] - lvl[f][v] & (1 << j))
			u = p[j][u];

	if (u == v)
		return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u];
}

int dp (int i, int k, int f) {
	if (i > n) return 0;
	int &res = mem[i][k][f];
	if (res != -1)
		return res;
	int a, b;

	if (i > 1) {
		a = lvl[ f ][ x[f][i] ] - lvl[ f ][ lca[ f ][ x[f][i] ][ x[f][i-1] ] ];
	} else {
		a = lvl[ f ][ x[f][i] ];
	}
	a += dp(i + 1, k, f);

	if (k) {
		b = lvl[ 1-f ][ x[1-f][i] ] - lvl[ 1-f ][ lca[ 1-f ][ x[1-f][i] ][ x[1-f][k] ] ];
	} else {
		b = lvl[ 1-f ][ x[1-f][i] ];
	}
	b += dp(i + 1, i - 1, 1 - f);

	return res = min(a, b);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	for (int f = 0; f < 2; f++) {
		cin >> m;
		res += m - 1;

		for (int i = 1; i <= m; i++)
			adj[i].clear();

		for (int i = 2; i <= m; i++) {
			cin >> p[0][i];
			adj[p[0][i]].pb(i);
		}

		for (int i = 1; i <= n; i++) {
			cin >> x[f][i];
			mn[x[f][i]] = i;
		}

		p[0][1] = 1;
		dfs(1, f);

		for (int j = 1; j < LG; j++)
			for (int i = 1; i <= m; i++)
				p[j][i] = p[j-1][p[j-1][i]];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
				lca[f][i][j] = LCA(i, j, f);
	}

	memset(mem, -1, sizeof(mem));
	cout << res - dp(1, 0, 0) << endl;

	return 0;
}