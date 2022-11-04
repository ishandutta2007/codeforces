#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const ll inf = 1e18;
const int MX = 200005;
int n, lvl[MX], p[MX], d;
ll a[MX], x[2][MX], y[2][MX], dp[MX];
vi adj[MX], pos[MX];

void clear () {
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		pos[i].clear();
		x[0][i] = x[1][i] = -inf;
		y[0][i] = y[1][i] = -inf;
	}
	d = 0;
}

void dfs (int u) {
	pos[lvl[u]].pb(u);
	d = max(d, lvl[u]);
	
	for (int v : adj[u])
		if (v != p[u]) {
			lvl[v] = lvl[u] + 1;
			p[v] = u;
			dfs(v);
		}
}

void solve () {
	cin >> n;
	clear();
	for (int u = 2; u <= n; u++) {
		int v;
		cin >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 2; i <= n; i++)
		cin >> a[i];
	dfs(1);
	
	y[0][0] = y[1][0] = 0;
	
	for (int i = 1; i <= d; i++)
		for (int u : pos[i]) {
			dp[u] = 0;
			
			dp[u] = max(dp[u], dp[p[u]] + a[p[u]] + x[0][i - 1]);
			dp[u] = max(dp[u], dp[p[u]] - a[p[u]] + x[1][i - 1]);
			dp[u] = max(dp[u], +a[p[u]] + y[0][i - 1]);
			dp[u] = max(dp[u], -a[p[u]] + y[1][i - 1]);
			
			x[0][i] = max(x[0][i], -a[u]);
			x[1][i] = max(x[1][i], a[u]);
			
			y[0][i] = max(y[0][i], dp[u] - a[u]);
			y[1][i] = max(y[1][i], dp[u] + a[u]);
		}
	
	ll res = 0;
	for (int u : pos[d]) {
		res = max(res, +a[u] + y[0][d]);
		res = max(res, -a[u] + y[1][d]);
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}