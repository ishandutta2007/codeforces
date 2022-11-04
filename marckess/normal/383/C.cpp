#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, q, a[MX], ft[2][MX], ini[MX], fin[MX], lvl[MX], cn;
vi adj[MX];

void update (int i, int k, int ft[]) {
	while (i < MX) {
		ft[i] += k;
		i += i & -i;
	}
}

int query (int i, int ft[]) {
	int s = 0;
	while (i) {
		s += ft[i];
		i -= i & -i;
	}
	return s;
}

void dfs (int u, int p) {
	ini[u] = ++cn;

	for (int v : adj[u])
		if (v != p) {
			lvl[v] = 1 - lvl[u];
			dfs(v, u);
		}

	fin[u] = cn;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;

	forn (i, n) cin >> a[i + 1];

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1, 1);

	while (q--) {
		int op, x, val;

		cin >> op >> x;
		if (op == 1) {
			cin >> val;
			update(ini[x], val, ft[lvl[x]]);
			update(fin[x] + 1, -val, ft[lvl[x]]);
		} else {
			cout << a[x] + query(ini[x], ft[lvl[x]]) - query(ini[x], ft[1 - lvl[x]]) << endl;
		}
	}

	return 0;
}