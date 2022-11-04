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

const int MX = 300005;
int n, m, k, ex[MX], c[MX], w[MX], in[MX];
vii gra[MX], adj[MX];
set<int> br;

int low[MX], dis[MX], cn = 0;

void dfs_br (int u, int p) {
	low[u] = dis[u] = ++cn;

	for (ii &v : gra[u]) {
		if (v.fi == p) continue;

		if (!dis[v.fi]) {
			dfs_br(v.fi, u);

			if (dis[u] < low[v.fi])
				br.insert(v.se);

			low[u] = min(low[u], low[v.fi]);
		} else {
			low[u] = min(low[u], dis[v.fi]);
		}
	}
}

int tot;
ll dp[MX], sz[MX];

void dfs_pre (int u) {
	dp[cn] += c[u];
	if (ex[u] && !sz[cn]) sz[cn] = 1, tot++;
	in[u] = cn;

	for (ii &v : gra[u]) {
		if (br.count(v.se) || in[v.fi] != -1) continue;
		dfs_pre(v.fi);
	}
}


void dfs1 (int u, int p) {
	for (ii &v : adj[u]) {
		if (v.fi == p) continue;
		dfs1(v.fi, u);

		dp[u] += max(0ll, dp[v.fi] - (!sz[v.fi] || sz[v.fi] == tot ? 0 : v.se));
		sz[u] += sz[v.fi];
	}
}

void dfs2 (int u, int p) {
	for (ii &v : adj[u]) {
		if (v.fi == p) continue;
		
		ll tdp = dp[u] - max(0ll, dp[v.fi] - (!sz[v.fi] || sz[v.fi] == tot ? 0 : v.se));
		ll tsz = sz[u] - sz[v.fi];

		dp[v.fi] += max(0ll, tdp - (!tsz || tsz == tot ? 0 : v.se));
		sz[v.fi] = tot;

		dfs2(v.fi, u);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	forn (i, k) {
		int v;
		cin >> v;
		ex[v - 1] = 1;
	}

	forn (i, n) cin >> c[i];
	forn (i, m) cin >> w[i];

	forn (i, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gra[u].emplace_back(v, i);
		gra[v].emplace_back(u, i);
	}

	dfs_br(1, 1);

	cn = 0;
	memset(in, -1, sizeof(in));
	forn (i, n) if (in[i] == -1) {
		dfs_pre(i);
		cn++;
	}

	forn (u, n) for (ii &v : gra[u]) if (br.count(v.se)) {
		adj[in[u]].emplace_back(in[v.fi], w[v.se]);
	}

	dfs1(0, 0);
	dfs2(0, 0);

	forn (i, n) cout << dp[in[i]] << " ";
	cout << endl;

	return 0;
}