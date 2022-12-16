#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n,deg[maxn],col[maxn],flg;
pii e[maxn];
vector <pii> to[maxn];
void dfs(int u, pii lst) {
	int cnt[2] = {0, 0};
	for (pii p : to[u]) {
		if (p.second == lst.second) continue;
		dfs(p.first, p), cnt[col[p.second]]++;
	}
	if (lst.second != -1) {
		if (deg[u] & 1) {
			if (cnt[1] == cnt[0]) col[lst.second] = 1;
			else if (cnt[1] == cnt[0] + 2) col[lst.second] = 0;
			else flg = 1;
		}
		else {
			if (cnt[1] == cnt[0] - 1) col[lst.second] = 1;
			else if (cnt[0] == cnt[1] - 1) col[lst.second] = 0;
			else flg = 1;
		}
	}
	else {
		if (deg[u] & 1) {
			if (cnt[1] != cnt[0] + 1) flg = 1;
		}
		else {
			if (cnt[1] != cnt[0]) flg = 1;
		}
	}
}

vector <int> g[maxn];
int ind[maxn],ord[maxn],tot;
void topsort() {
	queue <int> q;
	for (int i = 1; i < n; ++i)
		if (ind[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		ord[++tot] = u;
		for (int v : g[u])
			if (--ind[v] == 0) q.push(v);
	}
}

void work() {
	read(n);
	for (int i = 1; i <= n; ++i) deg[i] = 0, to[i].clear();
	for (int i = 1; i < n; ++i) {
		int x, y; read(x, y);
		e[i] = {x, y}, col[i] = 0, ind[i] = 0, g[i].clear();
		to[x].push_back({y, i}), to[y].push_back({x, i}), ++deg[x], ++deg[y];
	}
	flg = 0;
	dfs(1, {-1, -1});
	if (flg) return printf("NO\n"), void();
	printf("YES\n");
	for (int u = 1; u <= n; ++u) {
		vector <int> c[2], o;
		for (pii p : to[u]) c[col[p.second]].push_back(p.second);
		for (int i = 0; i < (int) c[0].size(); ++i) o.push_back(c[1][i]), o.push_back(c[0][i]);
		if (deg[u] & 1) o.push_back(c[1].back());
		for (int i = 0; i < (int) o.size() - 1; ++i) g[o[i + 1]].push_back(o[i]), ++ind[o[i]];
	}
	tot = 0, topsort();
	for (int i = 1; i <= tot; ++i) printf("%d %d\n", e[ord[i]].first, e[ord[i]].second);
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}