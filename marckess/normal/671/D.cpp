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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

void no () {
	cout << -1 << endl;
	exit(0);
}

const int MX = 300005;
const ll inf = 2e18;
int n, m, x, y, g[MX], h[MX], c[MX], lvl[MX];
vi pos[MX], adj[MX];
priority_queue<ii, vii, greater<ii>> pq[MX];
ll dp[MX], off[MX];

void pre (int u, int p) {
	for (int v : adj[u])
		if (v != p) {
			lvl[v] = lvl[u] + 1;
			pre(v, u);
		}
}

void dfs (int u, int p) {
	dp[u] = inf;
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	ll s = 0;
	for (int v : adj[u])
		if (v != p)
			s += dp[v];

	for (int i : pos[u])
		pq[u].emplace(s + c[i], lvl[g[i]]);

	for (int v : adj[u]) {
		if (v == p) continue;

		if (pq[u].size() > pq[v].size()) {
			while (pq[v].size()) {
				ii e = pq[v].top();
				pq[v].pop();
				e.fi += off[v] + s - dp[v] - off[u];		
				pq[u].push(e);
			}
		} else {
			off[v] += s - dp[v];

			while (pq[u].size()) {
				ii e = pq[u].top();
				pq[u].pop();
				e.fi += off[u] - off[v];
				pq[v].push(e);
			}

			swap(pq[u], pq[v]);
			swap(off[u], off[v]);
		}
	}

	if (pq[u].size())
		dp[u] = min(dp[u], pq[u].top().fi + off[u]);

	if (dp[u] == inf) no();
	while (pq[u].size() && pq[u].top().se >= lvl[u] - 1)
		pq[u].pop();
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	pre(1, 1);

	for (int i = 0; i < m; i++) {
		cin >> g[i] >> h[i] >> c[i];
		if (lvl[g[i]] > lvl[h[i]])
			swap(g[i], h[i]);
		if (g[i] != h[i])
			pos[h[i]].pb(i);
	}

	for (int v : adj[1]) {
		dfs(v, 1);
		dp[1] += dp[v];
	}

	cout << dp[1] << endl;

	return 0;
}