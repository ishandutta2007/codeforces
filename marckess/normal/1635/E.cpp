// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
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
int n, m, vis[MX], col[MX];
vii adj[MX];
vi dag[MX];

bool dfs (int u) {
	vis[u] = 1;
	
	for (auto &[v, _] : adj[u]) {
		if (vis[v]) {
			if (col[u] == col[v])
				return 0;
		} else {
			col[v] = 1 - col[u];
			if (!dfs(v))
				return 0;
		}
	}
	
	return 1;
}

vi topo;
int pos[MX];

bool dfs2 (int u) {
	vis[u] = 1;
	
	for (int v : dag[u]) {
		if (vis[v] == 1) return 0;
		
		if (!vis[v]) {
			if (!dfs2(v))
				return 0;
		}
	}
	
	topo.pb(u);
	vis[u] = 2;
	return 1;
}

void main_() {
	cin >> n >> m;
	
	forn (i, m) {
		int u, v, w;
		cin >> w >> u >> v;
		u--, v--;
		
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	forn (i, n)
		if (!vis[i]) {
			if (!dfs(i)) {
				cout << "NO" << endl;
				return;
			}
		}
	
	forn (u, n)
		if (!col[u])
			for (auto &[v, w] : adj[u]) {
				if (w == 1) {
					dag[v].pb(u);
				} else {
					dag[u].pb(v);
				}
			}

	memset(vis, 0, sizeof(vis));
	forn (u, n)
		if (!vis[u]) {
			if (!dfs2(u)) {
				cout << "NO" << endl;
				return;
			}
		}
	
	forn (i, n)
		pos[topo[i]] = i;
	
	cout << "YES" << endl;
	forn (i, n)
		cout << "LR"[col[i]] << " " << pos[i] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}