#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, u, v;
vvi adj;
vi col;

bool colorear (int u, int c) {
	col[u] = c;

	bool p = 1;
	for (int j : adj[u]) {
		if (col[j] != -1) {
			if (col[u] == col[j])
				return false;
		} else {
			p &= colorear(j, 1-c);
		}
	}

	return p;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	adj = vvi(n+1);
	col = vi(n+1, -1);

	for (int i = 0; i < m; i++) {
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bool pos = 1;
	for (int i = 1; i <= n; i++)
		if (col[i] == -1)
			pos &= colorear(i, 0);

	if (pos) {
		vi a[2];

		for (int i = 1; i <= n; i++) {
			a[col[i]].push_back(i);
		}

		cout << a[0].size() << endl;
		for (int x : a[0])
			cout << x << " ";
		
		cout << endl << a[1].size() << endl;
		for (int x : a[1])
			cout << x << " ";

		cout << endl;
 	} else {
		cout << -1 << endl;
	}

	return 0;
}