#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 3e5 + 10;
int n, h[N], mx[N];
vector<int> g[N];
ll ans = 0;
void dfs(int u, int fa) {
	mx[u] = 0;
	for(int v : g[u]) if(v != fa) {
		dfs(v, u);
		mx[u] = max(mx[u], mx[v]);
	}
	if(mx[u] < h[u]) ans += h[u] - mx[u], mx[u] = h[u];
	return;
}
void solve() {
	cin >> n;
	int rt = -1;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
		if(rt == -1 || h[rt] < h[i]) rt = i;
	}
	for(int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
	}
	int fi = 0, se = 0;
	for(int v : g[rt]) {
		dfs(v, rt);
		if(mx[v] > fi) se = fi, fi = mx[v];
		else if(mx[v] > se) se = mx[v];
	}
	ans += h[rt] - fi + h[rt] - se;
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
    return 0;
}