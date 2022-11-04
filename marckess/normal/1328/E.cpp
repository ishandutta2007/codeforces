#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, LG = 20;
int n, m, lvl[MX], p[MX][LG];
vi adj[MX];

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[u][0]) {
			p[v][0] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int lca (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	for (int j = 0; j < LG; j++)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[u][j];

	if (u == v) return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}

	return p[u][0];
}

int dis (int u, int v)  {
	int l = lca(u, v);
	return lvl[u] + lvl[v] - 2 * lvl[l];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	p[1][0] = 1;
	dfs(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[i][j] = p[p[i][j - 1]][j - 1];

	while (m--) {
		int k;
		vi v;

		cin >> k;
		v.resize(k);
		for (int &x : v) cin >> x;

		sort(all(v), [&] (int i, int j) {
			return lvl[i] > lvl[j];
		});

		int d = dis(v[0], 1), f = 1;
		for (int i = 1; i < k; i++)
			f &= dis(v[0], v[i]) + dis(v[i], 1) - 2 <= d;

		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}