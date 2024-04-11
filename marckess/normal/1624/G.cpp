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
int n, m, vis[MX], mk, res, cn;
vii adj[MX];

void dfs (int u) {
	vis[u] = 1;
	cn++;
	
	for (ii &v : adj[u]) {
		if (vis[v.fi]) continue;
		if (v.se & mk & ~res) continue;
		dfs(v.fi);
	}
}

void main_() {
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	mk = 0, res = 0;
	for (int j = 30; j >= 0; j--) {
		forn (i, n)
			vis[i + 1] = 0;
		cn = 0;
		mk |= 1 << j;
		
		dfs(1);
		
		if (cn != n)
			res |= 1 << j;
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}