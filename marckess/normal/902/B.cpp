#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define SET(p,k) memset(p, k, sizeof(p));
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, p[10005], c[10005], res = 0;
vvi adj;
bitset<10005> vis;

void dfs (int u, int co) {
	if (c[u] != co)
		res++;

	for (int v : adj[u]) {
		if (vis[v])
			continue;

		vis[v] = 1;
		dfs(v, c[u]);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	cin >> n;
	adj = vvi(n+1);

	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
		adj[i].push_back(p[i]);
	}

	for (int i = 1; i <= n; i++)
		cin >> c[i];

	vis[1] = 1;
	dfs(1, -1);

	cout << res << endl;

	return 0;
}