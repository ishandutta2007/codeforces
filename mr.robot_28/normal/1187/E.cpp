#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;

using namespace std;

const int N = 200 * 1000 + 13;

int n;
vector<int> g[N];

int siz[N];
li sum[N];

void init(int v, int p = -1){
	siz[v] = 1;
	sum[v] = 0;
	for (auto u : g[v]) if (u != p){
		init(u, v);
		siz[v] += siz[u];
		sum[v] += sum[u];
	}
	sum[v] += (siz[v] - 1);
}

li dp[N];

void dfs(int v, int p = -1){
	dp[v] = 0;
	li tot = 0;
	for (auto u : g[v]) if (u != p)
		tot += sum[u];
	for (auto u : g[v]) if (u != p){
		dfs(u, v);
		dp[v] = max(dp[v], (n - siz[u] - 1) + dp[u] + (tot - sum[u]));
	}
	if (g[v].size() == 1){
		dp[v] = n - 1;
	}
}

int main() {
	scanf("%d", &n);
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	if (n == 2) {
		cout << 3 << endl;
		return 0;
	}
	
	forn(i, n) if (int(g[i].size()) > 1){
		init(i);
		dfs(i);
		printf("%lld\n", dp[i] + n);
		break;
	}
	
	return 0;
}