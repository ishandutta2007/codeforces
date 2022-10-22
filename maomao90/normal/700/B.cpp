#include <bits/stdc++.h>
using namespace std;

int n, k;
bool isUni[200005];
vector <int> adjList[200005];
long long ans;

int cnt[200005];
int dfs(int u, int p) {
	if (isUni[u]) cnt[u]++;
	for (int v : adjList[u]) {
		if (v == p) continue;
		cnt[u] += dfs(v, u);
	}
	return cnt[u];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k * 2; i++) {
		int u; scanf("%d", &u);
		isUni[u] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j : adjList[i]) {
			int cur = min(cnt[i], cnt[j]);
			ans += min(cur, k * 2 - cur);
		}
	}
	printf("%lld\n", ans / 2);
	return 0;
}