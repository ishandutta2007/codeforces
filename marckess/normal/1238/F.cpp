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

const int MX = 300005;
int n, res;
vi adj[MX];
int x[MX], y[MX];

void dfs (int u, int p = -1) {
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);

			if (x[v] > x[u]) {
				y[u] = x[u];
				x[u] = x[v];
			} else if (x[v] > y[u]) {
				y[u] = x[v];
			}
		}

	int f = (int)adj[u].size() - bool(y[u]) - bool(x[u]) + 1;
	f += x[u] + y[u];
	res = max(res, f);

	x[u] += adj[u].size() - (p != -1) - bool(x[u]) + 1;
}

void solve () {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		x[i] = 0, y[i] = 0;
	}

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	res = 0;
	dfs(1);
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