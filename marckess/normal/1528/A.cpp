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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, l[MX], r[MX];
ll dp[MX][2];
vi adj[MX];

void dfs (int u, int p) {
	dp[u][0] = dp[u][1] = 0;
	
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			
			dp[u][0] += max(
				abs(l[u] - l[v]) + dp[v][0],
				abs(l[u] - r[v]) + dp[v][1]
			);
			
			dp[u][1] += max(
				abs(r[u] - l[v]) + dp[v][0],
				abs(r[u] - r[v]) + dp[v][1]
			);
		}
}

void solve () {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		adj[i].clear();
	}
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1, 1);
	cout << max(dp[1][0], dp[1][1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}