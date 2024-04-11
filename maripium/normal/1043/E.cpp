#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m;
long long x[N], y[N];
long long pre[N], suf[N];
vector<int> order;
long long res[N];

bool cmp(int u,int v) {
	return x[u] - y[u] < x[v] - y[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; ++i) order.push_back(i);
	sort(order.begin(), order.end(), cmp);
	for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + x[order[i - 1]];
	for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + y[order[i - 1]];
	for (int i = 1; i <= n; ++i) {
		int u = order[i - 1];
		res[u] += 1LL * (i - 1) * y[u] + pre[i - 1];
		res[u] += 1LL * (n - i) * x[u] + suf[i + 1];
	}
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		long long cost = min(x[u] + y[v], x[v] + y[u]);
		res[u] -= cost;
		res[v] -= cost; 
	}
	for (int i = 1; i <= n; ++i) cout << res[i] << ' '; cout << '\n';
}