#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, m, res[MX], vis[MX];
vi adj[MX], r;

void reset () {
	r.clear();
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		res[i] = 0;
		vis[i] = 0;
	}
}

void dfs (int u) {
	res[u] = vis[u] = 1;
	
	for (int v : adj[u])
		if (vis[v] && res[v])
			res[u] = 0;
	
	if (res[u])
		r.pb(u);
	
	for (int v : adj[u])
		if (!vis[v])
			dfs(v);
}

void solve () {
	cin >> n >> m;
	reset();
	
	forn (i, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			cout << "NO" << endl;
			return;
		}
	
	cout << "YES" << endl;
	cout << r.size() << endl;
	for (int k : r)
		cout << k << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}