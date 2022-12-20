#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e6 + 10;
int n,m,d,a[maxn],st[maxn],ans[maxn],cnt[maxn];
vector <int> A;
struct Edge {
	int v,nxt,id;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y, int z) {
	// printf("%d %d %d\n", x, y, z);
	e[++cnt_e] = {y, h[x], z};
	h[x] = cnt_e;
}

int ord[maxn],tot;
void dfs(int u) {
	for (; h[u]; h[u] = e[h[u]].nxt) {
		int v = e[h[u]].v, w = e[h[u]].id;
		if (ans[w]) continue;
		ans[w] = 1;
		dfs(v);
		ord[++tot] = w;
	}
}

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		st[i] = n + 1;
		int _n;
		scanf("%d", &_n);
		while (_n--) scanf("%d", &a[++n]), A.push_back(a[n]);
	}
	st[m + 1] = n + 1;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	d = A.size();
	for (int i = 1; i <= m; ++i) {
		for (int j = st[i]; j < st[i + 1]; ++j) {
			a[j] = lower_bound(A.begin(), A.end(), a[j]) - A.begin() + 1;
			cnt[a[j]]++, add(i, m + a[j], j), add(m + a[j], i, j);
		}
	}
	for (int i = 1; i <= d; ++i)
		if (cnt[i] & 1) return printf("NO\n"), 0;
	for (int i = 1; i <= m + d; ++i) dfs(i);
	for (int i = 1; i <= tot; ++i)
		ans[ord[i]] = (i & 1);
	printf("YES\n");
	for (int i = 1; i <= m; ++i) {
		for (int j = st[i]; j < st[i + 1]; ++j)
			printf(ans[j] ? "L" : "R");
		printf("\n");
	}
	return 0;
}