#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
int a[N], mx[N];
map<int,int> cnt[N];
long long res[N];

void dfs(int u,int p) {
	int bigChild = 0;
	for (int v : g[u]) if (v != p) {
		dfs(v, u);
		if (cnt[v].size() > cnt[bigChild].size()) bigChild = v;
	}
	mx[u] = mx[bigChild], res[u] = res[bigChild];
	cnt[u].swap(cnt[bigChild]);
	cnt[u][a[u]]++;
	if (cnt[u][a[u]] > mx[u]) {
		mx[u] = cnt[u][a[u]];
		res[u] = 0;
	}	
	if (cnt[u][a[u]] == mx[u]) {
		res[u] += a[u];
	}
	for (int v : g[u]) if (v != p && v != bigChild) {
		for (auto p : cnt[v]) {
			cnt[u][p.first] += p.second;
			if (cnt[u][p.first] > mx[u]) {
				mx[u] = cnt[u][p.first];
				res[u] = 0;
			}
			if (cnt[u][p.first] == mx[u]) {
				res[u] += p.first;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 1; ++i) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs(1, 1);
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
}