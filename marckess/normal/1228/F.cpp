#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = (1 << 17) + 5; 
int n, k, d[MX], p[MX], lvl[MX], pro[MX];
vi adj[MX], cd, res, gra[MX], g3, g1;
queue<int> q;

void dfs (int u, int par = -1) {
	if (adj[u].size() - (par != -1) == 3)
		g3.pb(u);
	if (adj[u].size() - (par != -1) == 1)
		g1.pb(u);

	pro[u] = lvl[u];
	for (int v : adj[u])
		if (v != par) {
			p[v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v, u);
			pro[u] = max(pro[u], pro[v]);
		}
}

bool mcDick (int u, int p, int lvl) {
	if (gra[u].size() - (p != -1) == 0)
		return lvl == k - 1;
	if (gra[u].size() - (p != -1) != 2)
		return 0;

	for (int v : gra[u])
		if (v != p && !mcDick(v, u, lvl + 1))
			return 0;

	return 1;
}

void solve (int r) {
	g1.clear(), g3.clear();
	lvl[r] = 0, p[r] = -1;
	dfs(r);

	if (g1.size() + g3.size() != 1) return;

	for (int i = 1; i <= n; i++)
		gra[i] = adj[i];

	if (g1.size()) {
		gra[g1.back()].pb(n + 1);
		gra[n + 1] = {g1.back()};

		if (mcDick(r, -1, 0))
			res.pb(g1.back());
	} else {
		int u = g3.back();
		vi aux;

		for (int v : adj[u])
			if (v != p[u] && pro[v] != pro[u])
				aux.pb(v);
		if (aux.size() != 2) return;

		gra[u].clear();
		for (int v : adj[u])
			if (v != aux[0] && v != aux[1])
				gra[u].pb(v);

		gra[u].pb(n + 1);
		gra[n + 1] = {u, aux[0], aux[1]};

		gra[aux[0]].clear();
		for (int v : adj[aux[0]])
			if (v != u)
				gra[aux[0]].pb(v);
		gra[aux[0]].pb(n + 1);

		gra[aux[1]].clear();
		for (int v : adj[aux[1]])
			if (v != u)
				gra[aux[1]].pb(v);
		gra[aux[1]].pb(n + 1);

		if (mcDick(r, -1, 0))
			res.pb(u);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> k;
	n = (1 << k) - 2;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(d, -1, sizeof(d));
	for (int i = 1; i <= n; i++)
		if (adj[i].size() == 1) {
			q.push(i);
			d[i] = 0;
		}

	int mx = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();

		for (int v : adj[u])
			if (d[v] == -1) {
				q.push(v);
				d[v] = d[u] + 1;
				mx = d[v];
			}
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == mx)
			cd.pb(i);

	if (cd.size() > 2) {
		cout << 0 << endl;
		return 0;
	}

	for (int x : cd)
		solve(x);

	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}