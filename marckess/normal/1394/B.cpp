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
int n, m, k, cn[10][10], ex[10][10];
set<ii> in[MX];
vii no[10][10];
vii adj[MX];

int go (int i) {
	if (i > k) return 1;
	int res = 0;

	forn (j, i) if (!cn[i][j] && !ex[i][j]) {
		for (const ii& x : no[i][j])
			cn[x.fi][x.se]++;

		res += go(i + 1);
		
		for (const ii& x : no[i][j])
			cn[x.fi][x.se]--;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;

	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(w, v);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
		forn (j, adj[i].size()) {
			ii p(adj[i].size(), j);

			if (in[adj[i][j].se].count(p)) ex[p.fi][p.se] = 1;
			in[adj[i][j].se].insert(p);
		}
	}

	for (int i = 1; i <= n; i++)
		for (const ii &x : in[i])
			for (const ii &y : in[i])
				if (x.fi < y.fi)
					no[x.fi][x.se].emplace_back(y);

	forn (i, 10) forn (j, 10) {
		vii &v = no[i][j];
		sort(all(v));
		v.erase(unique(all(v)), v.end());
	}

	cout << go(1) << endl;

	return 0;
}