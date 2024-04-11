#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, c, v, dp[MX][2], s;
vi adj[MX], res;
int vis[MX];

bool dfs (int u, int c) {
	if (dp[u][c] != -1)
		return dp[u][c];

	if (adj[u].empty()) return c;

	dp[u][c] = 0;

	for (int v : adj[u])
		if (dfs(v, 1-c)) {
			res.pb(v);
			return 1;
		}

	return 0;
}

bool cyc (int u) {
	vis[u] = 1;

	for (int v : adj[u]) {
		if (vis[v] == 1) return 1;
		if (!vis[v] && cyc(v)) return 1;
	}

	vis[u] = 2;
	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		while (c--) {
			cin >> v;
			adj[i].pb(v);
		}
	}
	cin >> s;

	if (dfs(s, 0)) {
		cout << "Win" << endl;
		res.pb(s);
		reverse(ALL(res));
		for (int x : res) cout << x << " ";
		cout << endl;
	} else if (cyc(s)) {
		cout << "Draw" << endl;
	} else {
		cout << "Lose" << endl;
	}

	return 0;
}