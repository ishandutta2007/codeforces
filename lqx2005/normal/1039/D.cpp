#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, pa[N], mx[N], d[N];
vector<int> g[N];
int ans[N];
int dep[N], id[N];
void adde(int u, int v) {g[u].push_back(v); }
int cmp(int x, int y) {return dep[x] > dep[y]; }
void Dfs(int u, int fa) {
	pa[u] = fa;
	dep[u] = dep[fa] + 1;
	mx[u] = 0;
	for(int &v : g[u]) {
		if(v == fa) continue;
		Dfs(v, u);
		mx[u] = max(mx[u], mx[v]);
	}
	mx[u]++;
	return;
}

int dfs(int k) {
	int c = 0;
	for(int i = 1; i <= n; i++) {
		int u = id[i];
		if(mx[u] * 2 - 1 < k) {
			d[u] = mx[u];
			continue;
		}
		int f = 0, s = 0;
		for(int &v : g[u]) {
			if(v == pa[u]) continue;
			if(f < d[v]) s = f, f = d[v];
			else s = max(s, d[v]);
		}
		if(f + s + 1 >= k) c++, d[u] = 0;
		else d[u] = f + 1;
	}
	return c;
}

int calc(int k) {
	if(k > n) return 0;
	if(ans[k] >= 0) return ans[k];
	ans[k] = dfs(k);
	return ans[k];
}

int find(int k, int l) {
	if(k <= 0) return n;
	int r = n / k;
	int b = r;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(calc(mid) >= k) l = mid + 1, b = mid;
		else r = mid - 1;
	}
	return b;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adde(u, v), adde(v, u);
	}
	Dfs(1, 0);
	for(int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	memset(ans, -1, sizeof(ans));
	int m = ceil(sqrt(n));
	int c = 0;
	for(int i = 1; i <= m; i++) {
		printf("%d\n", dfs(i));
	}
	c = calc(m + 1);
	for(int b = m + 1; b <= n; b++) {
		int e = find(c, b);
		for(int i = b; i <= e; i++) printf("%d\n", c);
		c = calc(e + 1);
		b = e;
	}
	return 0;
}