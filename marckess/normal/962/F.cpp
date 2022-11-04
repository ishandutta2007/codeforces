#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 100005;

int n, m, u[MX], v[MX], par[MX], p[MX], lvl[MX], cn[MX], ds[MX];
bitset<MX> us, vis;
vii adj[MX];

int parent (int a) {
	return a == ds[a] ? a : ds[a] = parent(ds[a]);
}

int sig (int a) {
	return p[parent(a)];
}

void joint (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return;

	if (lvl[p[a]] > lvl[p[b]])
		swap(a, b);

	ds[b] = a;
	cn[a] += cn[b];
}

void dfs (int u, int l) {
	lvl[u] = l;
	vis[u] = 1;

	for (ii &v : adj[u])
		if (!vis[v.fi]) {
			p[v.se] = u;
			par[v.fi] = v.se;
			us[v.se] = 1;

			dfs(v.fi, l+1);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(ds, ds+MX, 0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].emplace_back(v[i], i);
		adj[v[i]].emplace_back(u[i], i);
	}

	fill(p, p+m, n+1);
	lvl[n+1] = 1e9;

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			par[i] = -1;
			dfs(i, 0);
		}

	for (int i = 0; i < m; i++) {
		if (us[i]) continue;

		int a = u[i], b = v[i];

		while (a != b) {
			if (lvl[a] < lvl[b]) swap(a, b);
			joint(par[a], i);
			a = sig(par[a]);
		}

		cn[parent(i)]++;
	}

	vi res;
	for (int i = 0; i < m; i++)
		if (cn[parent(i)] == 1)
			res.pb(i+1);

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}