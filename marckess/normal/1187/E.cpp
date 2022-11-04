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

const int MX = 200005;
int n;
ll sz[MX], pts[MX], res;
vi adj[MX];

void dfs (int u, int p = -1) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
			pts[u] += pts[v];
		}
	pts[u] += sz[u];
}

void go (int u, int p, ll pp) {
	pts[u] -= sz[u];
	res = max(res, pts[u] + n + pp);
	for (int v : adj[u])
		if (v != p)
			go(v, u, pts[u] - pts[v] + pp + n - sz[v]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	res = pts[1];
	go(1, -1, 0);
	cout << res << endl;
 
	return 0;
}