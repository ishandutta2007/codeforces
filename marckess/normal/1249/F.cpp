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

const int MX = 205;
int n, k, a[MX], dp[MX][MX], aux[MX];
vi adj[MX];

void dfs (int u, int p) {
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	dp[u][0] = a[u];
	for (int v : adj[u])
		if (v != p) {
			int mx = 0;
			for (int j = k; j <= n; j++)
				mx = max(mx, dp[v][j]);
			dp[u][0] += mx;
		}

	for (int v : adj[u])
		if (v != p) {
			memset(aux, 0, sizeof(aux));

			for (int i = 1; i <= n; i++)
				for (int j = 0; j <= n; j++)
					if (i + j + 1 > k)
						aux[min(i, j + 1)] = max(aux[min(i, j + 1)], dp[u][i] + dp[v][j]);

			for (int i = 1; i <= n; i++)
				dp[u][i] = max(dp[u][i], aux[i]);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	forn (i, n)
		cin >> a[i+1];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1);

	int res = 0;
	for (int i = 0; i <= n; i++)
		res = max(res, dp[1][i]);
	cout << res << endl;

	return 0;
}