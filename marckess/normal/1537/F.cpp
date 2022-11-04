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

const int MX = 200005;
int n, m, v[MX], t[MX], lvl[MX], f, vis[MX];
vi adj[MX];

ll dfs (int u, int p) {
	ll d = t[u] - v[u];
	vis[u] = 1;
	
	for (int v : adj[u])
		if (v != p) {
			if (!vis[v]) {
				lvl[v] = lvl[u] + 1;
				d -= dfs(v, u);
			} else {
				if ((lvl[v] - lvl[u]) % 2 == 0)
					f = 1;
			}
		}

	return d;
}

void solve () {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vis[i] = 0;
	}
	
	forn (i, n) cin >> v[i + 1];
	forn (i, n) cin >> t[i + 1];
	
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	lvl[1] = 0;
	f = 0;
	ll d = dfs(1, 1);
	
	if (!d || (d % 2 == 0 && f)) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}