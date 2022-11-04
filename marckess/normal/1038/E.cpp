#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a, b, v;
int adj[5][5], mn[5][5], d[5];
int vis, res = 0, cn = 0;

int dfs (int u) {
	vis |= (1 << u);
	cn++;

	int res = 0;
	for (int v = 1; v < 5; v++) {
		if (!(vis & (1 << v)) && adj[u][v])
			res += dfs(v);
		if (u <= v)
			res += adj[u][v];
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	forn(i,5) forn(j,5) mn[i][j] = 1e9;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> v >> b;

		mn[a][b] = mn[b][a] = min(mn[a][b], v);
		adj[a][b] += v;
		d[a]++, d[b]++;
		if (a != b)
			adj[b][a] += v;
	}

	dfs(1);

	if (cn == 4 && d[1] % 2 && d[2] % 2 && d[3] % 2 && d[4] % 2) {
		for (int i = 1; i < 5; i++)
			for (int j = i+1; j < 5; j++)
				if (adj[i][j]) {
					adj[i][j] -= mn[i][j];
					adj[j][i] -= mn[j][i];
					
					vis = 0;
					for (int i = 1; i < 5; i++)
						if (!(vis & (1 << i)))
							res = max(res, dfs(i));

					adj[i][j] += mn[i][j];
					adj[j][i] += mn[j][i];
				}
	} else {
		vis = 0;
		for (int i = 1; i < 5; i++)
			if (!(vis & (1 << i)))
				res = max(res, dfs(i));
	}

	cout << res << endl;

	return 0;
}