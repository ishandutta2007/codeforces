#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define i64 long long
#define x first
#define y second
#define db double
using namespace std;
const int N = 1e5 + 10, P = 1e9 + 7;
int n, dep[N];
i64 a[N], ans = 0;
vector<int> g[N];
vector<pair<i64, int> > h[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	vector<pair<i64, int> > tmp = h[fa];
	tmp.push_back({0, dep[u]});
	for(pair<i64, int> &v : tmp) v.x = __gcd(v.x, a[u]);
	h[u].push_back(tmp[0]);
	for(int i = 1; i < sz(tmp); i++) {
		if(tmp[i].x == h[u].back().x) continue;
		h[u].push_back(tmp[i]);
	}
	(ans += a[u] % P * (dep[u] - h[u].back().y + 1) % P) %= P;
	for(int i = sz(h[u]) - 2; i >= 0; i--) {
		ans = (ans + h[u][i].x % P * (h[u][i + 1].y - h[u][i].y) % P) % P;		
	}
	for(int &v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	return;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}