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

const int MX = 200005;
int n, u, v, w;
ll dp[MX][4], res = 0;
vii adj[MX];

void dfs (int u, int p, int w) {
	for (ii &v : adj[u]) {
		if (v.fi == p) continue;

		dfs(v.fi, u, v.se);

		dp[u][0] += dp[v.fi][0];
		dp[u][1] += dp[v.fi][1];
		dp[u][2] += dp[v.fi][2];
		dp[u][3] += dp[v.fi][3];
	}

	for (ii &i : adj[u]) {
		int v = i.fi;
		if (v == p) continue;

		res += dp[v][0] * (dp[u][0] - dp[v][0]);
		res += dp[v][0] * (dp[u][1] - dp[v][1]);
		res += dp[v][0] * (dp[u][2] - dp[v][2]);

		res += dp[v][1] * (dp[u][1] - dp[v][1]);
		res += dp[v][1] * (dp[u][3] - dp[v][3]);
	}

	res += 2 * dp[u][0];
	res += 2 * dp[u][1];
	res += dp[u][2];
	res += dp[u][3];

	if (!w) {
		dp[u][2] += dp[u][1];
		dp[u][1] = dp[u][3] = 0;
	} else {
		dp[u][3] += dp[u][0];
		dp[u][0] = dp[u][2] = 0;
	}

	dp[u][w]++;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1, 1, 0);
	cout << res << endl;

	return 0;
}