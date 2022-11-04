#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, u, v, lvl[MX], p[MX][20], l[MX], root = 1;
vi adj[MX];
ll a[MX], res = 0;

void pre (int u, int w) {
	for (int v : adj[u])
		if (v != w) {
			lvl[v] = lvl[u] + 1;
			p[v][0] = u;
			pre (v, u);
		}
}

void dfs (int u, int w) {
	ll mn = 1e18;
	forn (i, 20) mn = min(mn, (i + 1) * a[p[u][i]] + a[u]);
	res += mn;

	for (int v : adj[u])
		if (v != w)
			dfs(v, u);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	forn (i, n) {
		cin >> a[i+1];
		if (a[i+1] < a[root])
			root = i+1;
	}

	forn (i, n-1) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	p[root][0] = root;
	pre (root, root);

	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j-1]][j-1];


	for (int v : adj[root])
		dfs (v, root);

	cout << res << endl;

	return 0;
}