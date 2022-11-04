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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 100005, LG = 20;
int n, p[LG][MX], lvl[MX], q;
vi adj[MX];

int lca (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	for (int j = 0; j < LG; j++)
		if (lvl[u] - lvl[v] & (1 << j))
			u = p[j][u];

	if (u == v) return u;

	for (int j = LG - 1; j >= 0; j--)
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u];
}

int dist (int a, int b) {
	return lvl[a] + lvl[b] - 2 * lvl[lca(a, b)];
}

void dfs (int u) {
	for (int v : adj[u])
		if (v != p[0][u]) {
			p[0][v] = u;
			lvl[v] = lvl[u] + 1;
			dfs(v);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	p[0][1] = 1;
	dfs(1);

	for (int j = 1; j < LG; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j - 1][p[j - 1][i]];

	cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;

		int d = dist(a, b);
		if (d <= k && k % 2 == d % 2) {
			cout << "yes" << endl;
			continue;
		}

		d = dist(a, x) + 1 + dist(y, b);
		if (d <= k && k % 2 == d % 2) {
			cout << "yes" << endl;
			continue;
		}

		d = dist(a, y) + 1 + dist(x, b);
		if (d <= k && k % 2 == d % 2) {
			cout << "yes" << endl;
			continue;
		}

		cout << "no" << endl;
	}

	return 0;
}