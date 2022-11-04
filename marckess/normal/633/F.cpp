#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, x[MX], a, b;
ll dp[MX][3][2];
vi adj[MX];

void maxi (int &a, int &b, int &c, int x, int i, int j) {
	if (dp[x][i][j] > dp[a][i][j]) {
		c = b;
		b = a;
		a = x;
	} else if (dp[x][i][j] > dp[b][i][j]) {
		c = b;
		b = x;
	} else if (dp[x][i][j] > dp[c][i][j]) {
		c = x;
	}
}

void dfs (int u, int p) {
	int a[3][2] = {0}, b[3][2] = {0}, c[3][2] = {0};

	for (int v : adj[u]) {
		if (p == v) continue;
		dfs(v, u);
		forn(i, 3) forn(j, 2) maxi(a[i][j], b[i][j], c[i][j], v, i, j);
	}

	dp[u][1][0] = max(dp[a[1][0]][1][0], 
					dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + x[u]
				);
	
	dp[u][2][0] = max({
					dp[a[2][0]][2][0],
					dp[a[1][0]][1][0] + dp[b[1][0]][1][0],
					//a[1][1] + b[0][1] + x[u],
					//a[0][1] + b[1][1] + x[u],
					dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + dp[c[0][1]][0][1] + x[u]
				});
	if (a[1][1] != a[0][1])
		dp[u][2][0] = max(dp[u][2][0], dp[a[1][1]][1][1] + dp[a[0][1]][0][1] + x[u]);
	dp[u][2][0] = max(dp[u][2][0], dp[b[1][1]][1][1] + dp[a[0][1]][0][1] + x[u]);
	dp[u][2][0] = max(dp[u][2][0], dp[a[1][1]][1][1] + dp[b[0][1]][0][1] + x[u]);

	if (a[0][1] != a[1][0] && b[0][1] != a[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + dp[a[1][0]][1][0] + x[u]);
	if (a[0][1] != b[1][0] && b[0][1] != b[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + dp[b[1][0]][1][0] + x[u]);
	dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + dp[c[1][0]][1][0] + x[u]);
 
	if (a[0][1] != a[1][0] && c[0][1] != a[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[c[0][1]][0][1] + dp[a[1][0]][1][0] + x[u]);
	if (a[0][1] != b[1][0] && c[0][1] != b[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[c[0][1]][0][1] + dp[b[1][0]][1][0] + x[u]);
	dp[u][2][0] = max(dp[u][2][0], dp[a[0][1]][0][1] + dp[c[0][1]][0][1] + dp[c[1][0]][1][0] + x[u]);

	if (c[0][1] != a[1][0] && b[0][1] != a[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[c[0][1]][0][1] + dp[b[0][1]][0][1] + dp[a[1][0]][1][0] + x[u]);
	if (c[0][1] != b[1][0] && b[0][1] != b[1][0])
		dp[u][2][0] = max(dp[u][2][0], dp[c[0][1]][0][1] + dp[b[0][1]][0][1] + dp[b[1][0]][1][0] + x[u]);
	dp[u][2][0] = max(dp[u][2][0], dp[c[0][1]][0][1] + dp[b[0][1]][0][1] + dp[c[1][0]][1][0] + x[u]);

	dp[u][0][1] = dp[a[0][1]][0][1] + x[u];
	
	dp[u][1][1] = max({
					dp[a[1][1]][1][1] + x[u],
					dp[a[1][0]][1][0] + x[u],
					dp[a[0][1]][0][1] + dp[b[0][1]][0][1] + x[u] //un camino acaba, otro continua
				});
	if (a[0][1] != a[1][0])
		dp[u][1][1] = max(dp[u][1][1], dp[a[0][1]][0][1] + dp[a[1][0]][1][0] + x[u]);
	dp[u][1][1] = max(dp[u][1][1], dp[a[0][1]][0][1] + dp[b[1][0]][1][0] + x[u]);
	dp[u][1][1] = max(dp[u][1][1], dp[b[0][1]][0][1] + dp[a[1][0]][1][0] + x[u]);

	dp[u][1][0] = max(dp[u][1][0], dp[u][0][1]);
	dp[u][2][0] = max(dp[u][2][0], dp[u][1][1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1, 1);

	ll res = 0;
	forn(i, 3) forn(j, 2) res = max(res, dp[1][i][j]);
	cout << res << endl;

	return 0;
}