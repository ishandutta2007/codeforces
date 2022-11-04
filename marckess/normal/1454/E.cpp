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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, vis[MX], in[MX], f, par[MX], cn;
ll res;
vi adj[MX];

void dfs1 (int u, int p) {
	vis[u] = 1;
	
	for (int v : adj[u])
		if (v != p) {
			if (!vis[v]) {
				par[v] = u;
				dfs1(v, u);
			} else if (!f) {
				f = 1;
				int a = u;
				while (a != v) {
					in[a] = 1;
					a = par[a];
				}
				in[v] = 1;
			}
		}
}

void dfs2 (int u, int p) {
	cn++;
	for (int v : adj[u])
		if (v != p)
			dfs2(v, u);
}

void solve () {
	cin >> n;
	
	f = 0;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		in[i] = 0;
		vis[i] = 0;
	}
	
	forn (i, n) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	res = 1ll * n * (n - 1);
	
	dfs1 (1, 1);
		
	for (int i = 1; i <= n; i++)
		if (in[i]) {
			cn = 1;
			for (int v : adj[i])
				if (!in[v])
					dfs2(v, i);
			res -= 1ll * cn * (cn - 1) / 2;
		}
	
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