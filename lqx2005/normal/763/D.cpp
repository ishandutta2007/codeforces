#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pii pair<i64, int>
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 1e5 + 10;
int n, siz[N], ans = 0, rt = -1;
vector<int> g[N];
map<u64, int> cnt;
u64 h1[N], h2[N], p[N];
mt19937_64 rng(__builtin_ia32_rdtsc());
void dfs1(int u, int fa) {
	siz[u] = 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs1(v, u);
		h1[u] += h1[v] * p[siz[v]];
		siz[u] += siz[v];
	}
	h1[u]++;
	return;
}

void dfs2(int u, int fa) {
	if(fa) h2[u] = h2[fa] * p[n - siz[fa]] + h1[fa] - h1[u] * p[siz[u]];
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs2(v, u);
	}
	return;
}

void dfs(int u, int fa) {
	if(fa) {
		cnt[h1[u]]--;
		cnt[h2[u]]++;
		if(cnt[h1[u]] == 0) {
			cnt.erase(h1[u]);
		}
	}
	if(ans < sz(cnt) + 1) {
		rt = u;
		ans = sz(cnt) + 1;
	}
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
	if(fa) {
		cnt[h1[u]]++;
		cnt[h2[u]]--;
		if(cnt[h2[u]] == 0) {
			cnt.erase(h2[u]);
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) p[i] = rng() | 1;
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v), g[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 2; i <= n; i++) cnt[h1[i]]++;
	dfs(1, 0);
	printf("%d\n", rt);
	return 0;
}