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
int n, m, col[MX], pos;
vii adj[MX];
vvi ed;

void dfs (int u) {
	for (ii &v : adj[u]) {
		if (col[v.fi] == -1) {
			col[v.fi] = col[u] ^ v.se;
			dfs(v.fi);
		} else {
			pos &= (col[u] ^ col[v.fi]) == v.se;
		}
	}
}

void main_() {
	cin >> n >> m;
	
	ed.clear();
	pos = 1;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		col[i] = -1;
	}
	
	forn (i, n - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		
		ed.pb({u, v, w});
		if (w != -1) {
			adj[u].pb({v, __builtin_popcount(w) & 1});
			adj[v].pb({u, __builtin_popcount(w) & 1});
		}
	}
	
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	forr (i, 1, n)
		if (col[i] == -1) {
			col[i] = 0;
			dfs(i);
		}
	
	if (pos) {
		cout << "YES" << endl;
		for (vi &v : ed) {
			cout << v[0] << " " << v[1] << " ";
			if (v[2] == -1) cout << (col[v[0]] ^ col[v[1]]) << endl;
			else cout << v[2] << endl;
		}
	} else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}