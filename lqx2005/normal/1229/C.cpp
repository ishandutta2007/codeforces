#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define x first
#define y second
#define db double
using namespace std;
const int N = 1e5 + 10;
int n, m, q, a[N];
vector<int> g[N], e[N];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i] = i;
	i64 ans = 0;
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) for(int &v : g[i]) if(a[v] > a[i]) e[i].push_back(v);
	for(int i = 1; i <= n; i++) for(int &v : e[i]) ans += sz(e[v]);
	cin >> q;
	cout << ans << endl;
	for(int i = 1; i <= q; i++) {
		int u;
		cin >> u;
		ans -= 1ll * sz(e[u]) * (sz(g[u]) - sz(e[u]));
		for(int &v : e[u]) ans -= sz(e[v]), e[v].push_back(u), ans += sz(g[v]) - sz(e[v]);
		e[u].clear();
		cout << ans << endl;
	}
	return 0;
}