#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, s, t, u, v, res = 0;
int d[MX][MX], gra[MX][MX];
vi adj[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(d, -1, sizeof(d));

	cin >> n >> m >> s >> t;

	while (m--) {
		cin >> u >> v;
		gra[u][v] = gra[v][u] = 1;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		d[i][i] = 0;

		while (q.size()) {
			int u = q.front();
			q.pop();

			for (int v : adj[u])
				if (d[i][v] == -1) {
					d[i][v] = d[i][u] + 1;
					q.push(v);
				}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			int e = min(d[s][i] + 1 + d[j][t], d[s][j] + 1 + d[i][t]);
			if (!gra[i][j] && e >= d[s][t]) {
				res++;
			}
		}
	cout << res << endl;

	return 0;
}