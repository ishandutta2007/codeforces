#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, d[2005][2005], d2[2005][2005];
int a[4000005], b[4000005], w[4000005], q[4000005], m = 0;
vvi adj;
bitset<2005> vis;

struct DS {
	vi p;

	DS (int n) : p(n+1) {
		iota(p.begin(), p.end(), 0);
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	bool joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (a == b)
			return false;

		p[a] = b;
		return true;
	}
};

void kruskal () {
	DS ds(n);

	sort(q, q+m, [&] (int a, int b) {
		return w[a] < w[b];
	});

	for (int i = 0; i < m; i++) {
		int u = q[i];

		if (ds.joint(a[u], b[u])) {
			adj[a[u]].push_back(b[u]);
			adj[b[u]].push_back(a[u]);
		}
	}
}

void dfs (int act, int u, int dis) {
	vis[u] = 1;
	d2[act][u] = dis;

	for (int v : adj[u])
		if (!vis[v])
			dfs(act, v, dis + d[u][v]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	for (int i = 0; i < n; i++) {
		if (d[i][i]) {
			cout << "NO" << endl;
			return 0;
		}

		for (int j = i + 1; j < n; j++) {
			if (d[i][j] != d[j][i] || !d[i][j]) {
				cout << "NO" << endl;
				return 0;
			}

			a[m] = i;
			b[m] = j;
			w[m] = d[i][j];
			q[m] = m++;
		}
	}

	adj = vvi(n);
	kruskal();

	for (int i = 0; i < n; i++) {
		vis.reset();
		dfs(i, i, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] != d2[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}