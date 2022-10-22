#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 10, P = 998244353;
int n, cnt[N], mx[N], val[N];
int pr[N], vis[N], tot = 0, mp[N];
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = (ll)a * a % P) if(b & 1) c = (ll)c * a % P;
	return c;
}
void sieve(int n) {
	vis[1] = 1, mp[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pr[++tot] = i, mp[i] = i;
		for(int j = 1; j <= tot && i * pr[j] <= n; j++) {
			vis[i * pr[j]] = 1, mp[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
	return;
}
vector<tuple<int, int, int>> g[N];
void add(int x, int y) {
	cnt[x] += y, mx[x] = max(mx[x], cnt[x]);
}
void dfs(int u, int fa) {
	for(auto [v, x, y] : g[u]) {
		if(v == fa) continue;
		for(int d = y; mp[d] > 1; add(mp[d], -1), d /= mp[d]);
		for(int d = x; mp[d] > 1; add(mp[d], 1), d /= mp[d]);
		val[v] = (ll)val[u] * y % P * power(x, P - 2) % P;
		dfs(v, u);
		for(int d = x; mp[d] > 1; add(mp[d], -1), d /= mp[d]);
		for(int d = y; mp[d] > 1; add(mp[d], 1), d /= mp[d]);
	}
	return;
}
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) g[i].clear(), cnt[i] = 0, mx[i] = 0;
	for(int i = 1, u, v, x, y; i < n; i++) {
		cin >> u >> v >> x >> y;
		g[u].emplace_back(v, x, y);
		g[v].emplace_back(u, y, x);
	}
	val[1] = 1;
	dfs(1, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++) (ans += val[i]) %= P;
	for(int i = 1; i <= n; i++) if(mx[i]) (ans = (ll)ans * power(i, mx[i]) % P) %= P;
	cout << ans << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	sieve(N - 10);
	int t;
	for(cin >> t; t--; ) {
		solve();
	}
    return 0;
}