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

const int MX = 300005;
int n, a[MX], cn[MX], res[MX];
int in, ini[MX], fin[MX], ft[MX];
vi adj[MX];

void update (int i, int k) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void dfs1 (int u, int p = -1) {
	cn[u] = a[u];
	ini[u] = ++in;
	
	for (int v : adj[u])
		if (v != p) {
			dfs1(v, u);
			cn[u] += cn[v];
		}
	
	fin[u] = in;
}

void dfs2 (int u, int p = -1) {
	int x = 0, y = 0;
	for (int v : adj[u])
		if (a[v]) {
			x++;
			y = v;
		}
	
	for (int v : adj[u])
		if (x >= 2 || (x == 1 && v != y))
			if (cn[u] - cn[v] >= 2) {
				if (v == p) {
					update(1, 1);
					update(ini[u], -1);
					update(fin[u] + 1, 1);
				} else {
					update(ini[v], 1);
					update(fin[v] + 1, -1);
				}
			}
	
	for (int v : adj[u])
		if (v != p) {
			int sz = cn[u], tmp = cn[v];
			cn[u] -= cn[v];
			cn[v] = sz;
			
			dfs2(v, u);	
			
			cn[u] = sz;
			cn[v] = tmp;
		}
}

void main_() {
	cin >> n;	
	
	forn (i, n)
		cin >> a[i + 1];
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs1(1);
	dfs2(1);
	
	for (int u = 1; u <= n; u++) {
		res[u] |= bool(query(ini[u]));
		
		for (int v : adj[u])
			res[u] |= a[v];
		res[u] |= a[u];
		
		cout << res[u] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}