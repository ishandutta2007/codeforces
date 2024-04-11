#include <bits/stdc++.h>
#define i64 long long
#define u64 unsigned long long
#define sz(a) int((a).size())
#define x first
#define y second
#define pb push_back
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int n, k, sze[N];
i64 ans = 0;
vi g[N];

void dfs(int u, int fa) {
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
		sze[u] += sze[v];
	}
	ans += min(sze[u], 2 * k - sze[u]);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= 2 * k; i++) {
		int x;
		cin >> x;
		sze[x]++;
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}