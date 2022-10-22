#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 3e5 + 10, B = 600;
int n, m, a[N], b[N], tot = 0, cnt[N];
map<pair<int, int>, vector<pair<int, int>>> e;
map<int, int> g[N];
vector<int> p[N];
void solve() {
	e.clear();
	cin >> n >> m;
	for(int i = 1; i <= n; i++) p[i].clear();
	for(int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	tot = unique(b + 1, b + n + 1) - (b + 1);
	for(int i = 1; i <= tot; i++) cnt[i] = 0;
	for(int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b, cnt[a[i]]++;
	vector<int> c;
	for(int i = 1; i <= tot; i++) c.push_back(cnt[i]), p[cnt[i]].push_back(i);
	for(int i = 1; i <= n; i++) sort(p[i].begin(), p[i].end(), [&](int x, int y) {return b[x] > b[y]; });
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		u = lower_bound(b + 1, b + tot + 1, u) - b, v = lower_bound(b + 1, b + tot + 1, v) - b;
		if(cnt[u] > cnt[v]) swap(u, v);
		e[{cnt[u], cnt[v]}].emplace_back(u, v);
	}
	for(int u = 1; u <= n; u++) e[{cnt[u], cnt[u]}].emplace_back(u, u);
	ll ans = 0;
	for(auto a : c) {
		for(auto b : c) {
			if(a > b) continue;
			for(auto [u, v] : e[{a, b}]) g[u][v] = 1, g[v][u] = 1;
			for(int u : p[a]) {
				for(int v : p[b]) {
					if(!g[u].count(v)) {
						ans = max(ans, 1ll * (cnt[u] + cnt[v]) * (::b[u] + ::b[v]));
						// cout << 1ll * (cnt[u] + cnt[v]) * (::b[u] + ::b[v]) << " " << u <<" " << v << endl;
						break;
					}
				}
				if(g[u].empty()) break;
			}
			for(auto [u, v] : e[{a, b}]) g[u].clear(), g[v].clear();
		}
	}
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}