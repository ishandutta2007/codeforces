#include <bits/stdc++.h>
using namespace std;

char c[200005], t[200005];
int lc[200005], rc[200005], fa[200005], pos[200005], good[200005], f[200005], siz[200005], tr[200005], id[200005], dep[200005], tops[200005];
int n, k, len, dfn;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

struct fenwick {
	int f[200005];

	void add(int x, int y) {
		while (x <= n) {
			f[x] += y;
			x += (x & -x);
		}
	}

	int query(int x) {
		int ans = 0;
		while (x) {
			ans += f[x];
			x &= (x - 1);
		}
		return ans;
	}
} t1, t2;

void dfs(int u) {
	if (!u) return;
	tops[u] = ++dfn;
	if (lc[u]) dep[lc[u]] = dep[u] + 1;
	dfs(lc[u]);
	++len; t[len] = c[u]; id[len] = u; pos[u] = len;
	if (rc[u]) dep[rc[u]] = dep[u] + 1;
	dfs(rc[u]);
	siz[u] = siz[lc[u]] + siz[rc[u]] + 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		cin >> lc[i] >> rc[i];
		if (lc[i]) fa[lc[i]] = i;
		if (rc[i]) fa[rc[i]] = i;
	}
	dep[1] = 1; dfs(1);
	char las = 'a' - 1;
	for (int i = n; i >= 1; i--) {
		if (i != n && t[i] != t[i + 1]) las = t[i + 1];
		if (t[i] < las) good[i] = 1;
	}
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= n; i++) {
		if (!good[pos[i]] && rc[i]) {
			t1.add(tops[rc[i]], 1);
			t1.add(tops[rc[i]] + siz[rc[i]], -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		if (f[u] == u && good[i] && t1.query(tops[u]) == 0 && dep[u] - t2.query(tops[u]) <= k) {
			int now = u;
			while (now) {
				f[now] = find(fa[now]);
				if (!good[pos[now]] && rc[now]) {
					t1.add(tops[rc[now]], -1);
					t1.add(tops[rc[now]] + siz[rc[now]], 1);
				}
				t2.add(tops[now], 1);
				t2.add(tops[now] + siz[now], -1);
				--k;
				now = f[now];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << t[i];
		if (f[id[i]] != id[i]) cout << t[i];
	}
	cout << endl;
	return 0;
}