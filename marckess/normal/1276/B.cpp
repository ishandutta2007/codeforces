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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, a, b, x, y, vis[MX];
vi adj[MX];

void dfs (int u, int f) {
	if (u == b) return;
	vis[u] |= f;

	for (int v : adj[u])
		if (!(vis[v] & f))
			dfs(v, f);
}

void solve () {
	cin >> n >> m >> a >> b;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = 0;
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(a, 1);
	swap(a, b);
	dfs(a, 2);

	x = y = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1) x++;
		if (vis[i] == 2) y++;
	}

	cout << ll(x - 1) * (y - 1) << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}