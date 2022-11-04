#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, b, d[5005], c[5005], p[5005], mx = 0, tam[5005] = {0};
int res[5005][5005][2], vb = 1e9+1;
vvi adj;

void dfs (int u) {
	res[u][0][0] = res[u][0][1] = 0;
	tam[u] = 1;

	for (int v : adj[u]) {
		dfs(v);

		for (int j = tam[u]; j >= 0; j--) {
			for (int i = tam[v]; i >= 0; i--) {
				res[u][i+j][0] = min(res[u][i+j][0], res[u][j][0] + res[v][i][0]);
				res[u][i+j][1] = min(res[u][i+j][1], res[u][j][1] + min(res[v][i][1], res[v][i][0]));
			}
		}

		tam[u] += tam[v];
	}

	for (int i = tam[u]; i > 0; i--) {
		res[u][i][0] = min(res[u][i][0], res[u][i-1][0] + c[u]);
		res[u][i][1] = res[u][i-1][1] + d[u];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> b;
	adj = vvi(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
		d[i] = c[i] - d[i]; 

		if (i > 1) {
			cin >> p[i];
			adj[p[i]].push_back(i);
		}
	}

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int f = 0; f < 2; f++)
				res[i][j][f] = vb;

	dfs(1);

	for (int i = 0; i <= n; i++) {
		if (res[1][i][1] <= b)
			mx = i;
		if (res[1][i][0] <= b)
			mx = i;
	}

	cout << mx << endl;

	return 0;
}