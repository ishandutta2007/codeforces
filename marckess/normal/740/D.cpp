#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005, LMX = 19;
int n, p[MX][LMX], acu[MX], a[MX], res[MX];
vi adj[MX];
ll w[MX][LMX];

int dfs (int u) {
	int x = 0, f = 0;

	for (int v : adj[u])
		x += dfs(v);

	int v = u;
	for (int j = LMX - 1; j >= 0; j--) {
		if (w[v][j] <= a[u]) {
			a[u] -= w[v][j];
			v = p[v][j];
		}
	}

	if (v != u) {
		f = 1;
		if (v != 1)
			acu[p[v][0]]++;
	}

	x -= acu[u];
	return f + (res[u] = x);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	p[1][0] = 1;
	w[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		cin >> p[i][0] >> w[i][0];
		adj[p[i][0]].push_back(i);
	}

	for (int j = 1; j < LMX; j++) {
		for (int i = 1; i <= n; i++) {
			w[i][j] = w[i][j-1] + w[p[i][j-1]][j-1];
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}