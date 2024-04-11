#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
vector<int> child[N];
int le[N], ri[N];
int a[N];
int cnt;

void dfs(int u) {
	le[u] = ++cnt; a[cnt] = u;
	for (int v : child[u]) dfs(v);
	ri[u] = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		child[p].push_back(i);
	} 
	dfs(1);
	while (q--) {
		int u, k; cin >> u >> k;
		if (ri[u] - le[u] + 1 < k) cout << -1 << '\n';
		else cout << a[le[u] + k - 1] << '\n';
	}
}