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
int n, c[MX], p[MX], sz[MX], dp[MX];
vi adj[MX];

int dfs (int u) {
	for (int v : adj[u])
		dfs(v);

	if (c[u]) {
		for (int v : adj[u])
			dp[u] = max(dp[u], sz[u] - sz[v] + dp[v]);
	} else {
		for (int v : adj[u])
			dp[u] += dp[v];
	}
	
	return dp[u];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}

	for (int i = n; i >= 1; i--) {
		if (i > 1 && adj[i].size() == 0) sz[i] = 1;
		for (int v : adj[i])
			sz[i] += sz[v];
	}

	cout << dfs(1) + 1 << endl;

	return 0;
}