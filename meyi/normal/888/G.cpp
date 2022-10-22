#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
int read() {
	int res = 0; char c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) res = res * 10 + (c ^ 48), c = getchar();
	return res;
}
const int N = 2e5 + 5;
int n, a[N], blo, cost[N], pos[N];
struct disjoint_sets_union {
	int par[N];
	void init() { for(int i = 1; i <= n; i++) par[i] = i; }
	int find(int p) { return par[p] == p ? p : par[p] = find(par[p]); }
} dsu;
int tot, ch[N * 50][2], rt[N], siz[N * 50], ex[N * 50];
void insert(int &u, int dep, int val, int p) {
	if(!u) u = ++tot;
	if(dep < 0) { siz[u] = 1; ex[u] = p; return; } 
	insert(ch[u][val >> dep & 1], dep - 1, val, p);
	siz[u]++;
}
int query(int u, int v, int val) {
	for(int dep = 30; ; dep--) {
		if(dep < 0) return ex[u];
		int dir = val >> dep & 1;
		if(ch[u][dir] && siz[ch[u][dir]] > siz[ch[v][dir]]) u = ch[u][dir], v = ch[v][dir];
		else u = ch[u][dir ^ 1], v = ch[v][dir ^ 1];
	}
}
void merge(int &u, int v) {
	if(!u || !v) { u = u | v; return; }
	siz[u] += siz[v];
	merge(ch[u][0], ch[v][0]);
	merge(ch[u][1], ch[v][1]);
}
int main() {
	n = read(); dsu.init();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1); blo=n = unique(a + 1, a + n + 1) - a - 1;
	for(int i = 1; i <= n; i++) insert(rt[i], 30, a[i], i), insert(rt[0], 30, a[i], i);
	long long ans = 0;
	while(blo > 1) {
		memset(pos, -1, sizeof(pos));
		memset(cost, 0x7f, sizeof(cost));
		for(int i = 1; i <= n; i++) {
			int bel = dsu.find(i), to = query(rt[0], rt[bel], a[i]);
			if(cost[bel] > (a[i] ^ a[to])) pos[bel] = to, cost[bel] = a[i] ^ a[to];
		}
		for(int i = 1; i <= n; i++) {
			if(dsu.find(i) == i) {
				int u = i, v = dsu.find(pos[i]);
				if(u == v) continue;
				ans += cost[u];
				if(siz[u] < siz[v]) swap(u, v);
				dsu.par[v] = u;
				merge(rt[u], rt[v]);
				blo--;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}