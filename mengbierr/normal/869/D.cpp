#include <bits/stdc++.h>
using namespace std;
int n, m, x[10], y[10];
int sz[1000];
int mod = 1000000007;
map<int, int> g, id;
set<int> s;
vector<int> a[1000];
long long ans;
bool vis[1000];
void gao(int x) {
	while (x > 0) {
		s.insert(x);
		x /= 2;
	}
}

void dfs(int x, long long b) {
	vis[x] = true;
	ans += b * sz[x];
	ans %= mod;
	for (int i: a[x]) {
		if (!vis[i]) {
			dfs(i, b);
		}
	}
	vis[x] = false;
}

int calc(int x) {
	int left = x;
	int right = x;
	int re = 0;
	while (true) {
		if (left > n) {
			return re;
		}
		re += min(right, n) - left + 1;
		right = right * 2 + 1;
		left = left * 2;
	}
	return re;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		gao(x[i]);
		gao(y[i]);
	}
	s.insert(1);
	for (int i: s) {
		if (s.find(2 * i) == s.end() && s.find(2 * i + 1) == s.end()) {
			g[i] = calc(i);
		} else {
			g[i] = 1;
			if (2 * i <= n && s.find(2 * i) == s.end()) {
				g[2 * i] = calc(2 * i);
			}
			if (2 * i + 1 <= n && s.find(2 * i + 1) == s.end()) {
				g[2 * i + 1] = calc(2 * i + 1);
			}
		}
	}
	for (pair<int, int> sth: g) {
		int i = sth.first;
		int u = id.size();
		id[i] = u;
		sz[u] = g[i];
	}
	assert(g.size() == id.size());
	int nn = g.size();
	for (pair<int, int> sth: id) {
		int i = sth.first;
		if (i == 1) {
			continue;
		}
		int child = id[i];
		int father = id[i / 2];
		a[child].push_back(father);
		a[father].push_back(child);
	}
	for (int i = 0; i < m; i++) {
		int first = id[x[i]];
		int second = id[y[i]];
		a[first].push_back(second);
		a[second].push_back(first);
	}
	for (int i = 0; i < nn; i++) {
		dfs(i, sz[i]);
	}
	printf("%lld\n", ans);
	return 0;
}