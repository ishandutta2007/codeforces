#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int cost[N];
vector<int> g[N];
vector<array<int, 4>> vals;
int par[N];
int cnt;

void dfs(int u,int p) {
	int l = cnt;
	bool leaf = true;
	for (int v : g[u]) {
		if (v != p) {
			leaf = false;
			dfs(v, u);
		}
	}
	if (leaf) {
		++cnt;
	}
	int r = cnt;
	vals.push_back({cost[u], l, r, u});
}

int anc(int u) {
	if (par[u] == u) {
		return u;
	} else {
		return par[u] = anc(par[u]);
	}
}

bool join(int u,int v) {
	u = anc(u), v = anc(v);
	if (u == v) {
		return false;
	} else {
		par[v] = u;
		return true; 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}
	
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, -1);
	
	for (int i = 0; i <= cnt; ++i) {
		par[i] = i;
	}
	sort(vals.begin(), vals.end());
	
	int l = 0;
	long long ans = 0;
	vector<int> cnd;
	
	while (l < n) {
		int r = l;
		while (r + 1 < n && vals[r + 1][0] == vals[l][0]) {
			++r;
		}
		for (int i = l; i <= r; ++i) {
			if (anc(vals[i][1]) != anc(vals[i][2])) {
				cnd.push_back(vals[i][3]);
			}
		}
		for (int i = l; i <= r; ++i) {
			if (join(vals[i][1], vals[i][2])) {
				ans += vals[i][0];
			}
		}
		l = r + 1;
	}
	
	sort(cnd.begin(), cnd.end());
	cout << ans << ' ' << cnd.size() << '\n';
	for (int v : cnd) {
		cout << v << ' ';
	}
}