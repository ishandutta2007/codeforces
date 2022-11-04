#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

struct DS {
	vi p, rk;

	DS (int n) : p(n+1), rk(n+1) {
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);

		if (a != b) {
			if (rk[a] > rk[b]){
				p[b] = a;
			} else {
				p[a] = b;
				if (rk[a] == rk[b])
					rk[b]++;
			}
		}
	}
};

int n, m, k, t[100005], c[505], u, v, x, p[100005] = {-1};
vvi adj;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> c[i];

	for (int i = 1, j = 0; i <= n; i++) {
		if (c[j] == 0)
			j++;

		t[i] = j;
		c[j]--;
	}

	DS ds(n);
	adj = vvi(k, vi(k, 1e18));
	while (m--) {
		cin >> u >> v >> x;

		if (!x) {
			ds.joint(u, v);
		}

		if (t[u] != t[v]) {
			adj[t[u]][t[v]] = min(ll(x), adj[t[u]][t[v]]);
			adj[t[v]][t[u]] = min(ll(x), adj[t[v]][t[u]]);
		}
	}

	SET(p, -1);

	for (int i = 1; i <= n; i++) {
		if (p[t[i]] == -1) {
			p[t[i]] = ds.parent(i);
		} else if (p[t[i]] != ds.parent(i)) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (int i = 0; i < k; i++)
		adj[i][i] = 0;

	for (int l = 0; l < k; l++)
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++)
				adj[i][j] = min(adj[i][j], adj[i][l] + adj[l][j]);

	cout << "Yes" << endl;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (adj[i][j] == 1e18)
				cout << -1 << " ";
			else
				cout << adj[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}