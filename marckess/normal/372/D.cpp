#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005, LMX = 18;

int n, k, p[LMX][MX], a, b, pos[MX], inv[MX], lvl[MX], cn = 0;
int acu = 0, res = 0;
vi adj[MX];
set<int> st;

void dfs (int u) {
	pos[u] = ++cn;
	inv[cn] = u;

	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	for (int j = LMX-1; j >= 0; j--)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];

	if (u == v) return u;

	for (int j = LMX-1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u];
}

inline int dist (int u, int v) {
	int lca = LCA(u, v);
	return lvl[u] + lvl[v] - 2 * lvl[lca]; 
}

inline int cost (int u) {
	if (st.empty()) return 1;
	int s, t;

	auto it = st.upper_bound(pos[u]);
	if (it == st.end()) t = *st.begin();
	else t = *it;
	
	if (it == st.begin()) it = st.end();
	it--;
	s = *it;

	return (dist(u, inv[s]) + dist(u, inv[t]) - dist(inv[s], inv[t])) / 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	p[0][1] = 1;
	dfs(1);

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j-1][p[j-1][i]];

	int i = 1, j = 1;

	while (i <= n) {
		while (j <= n && acu + cost(j) <= k) {
			acu += cost(j);
			st.insert(pos[j]);
			j++;
		}

		res = max(res, j - i);
		st.erase(pos[i]);
		acu -= cost(i);
		i++;
	}

	cout << res << endl;

	return 0;
}