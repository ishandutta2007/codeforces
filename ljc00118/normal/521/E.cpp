#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
  
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5;

vector <int> adj[N];
int fa[N], d[N], f[N], x[N], y[N], id[N];
int n, m, tot;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u) {
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa[u]) continue;
		fa[v] = u; d[v] = d[u] + 1; dfs1(v);
	}
}

int lca(int u, int v) {
	while (u != v) {
		if (d[u] < d[v]) swap(u, v);
		u = fa[u];
	}
	return u;
}

vector <int> getpath(int u, int v) {
	vector <int> ans[2];
	bool opt = 0;
	while (u != v) {
		if (d[u] < d[v]) swap(u, v), opt ^= 1;
		ans[opt].push_back(u); u = fa[u];
	}
	ans[0].push_back(u);
	for (int i = (int)ans[1].size() - 1; i >= 0; i--) ans[0].push_back(ans[1][i]);
	return ans[0];
}

int vis[N];
bool check(vector <int> a, vector <int> b) {
	memset(vis, 0, sizeof(vis));
	for (auto i : a) vis[i] = 1;
	for (auto i : b) if (vis[i]) return 0;
	return 1;
}

vector <int> merge(vector <int> a, vector <int> b) {
	for (auto i : b) a.push_back(i);
	return a;
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		if (find(u) != find(v)) {
			f[find(u)] = find(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		} else ++tot, x[tot] = u, y[tot] = v;
	}
	for (int i = 1; i <= n; i++) if (!d[i]) dfs1(i);
	for (int i = 1; i <= tot; i++) {
		int u = x[i], v = y[i], I = 0;
		while (u != v) {
			if (d[u] < d[v]) swap(u, v);
			if (id[u]) { I = id[u]; break; }
			id[u] = i; u = fa[u];
		}
		if (I) {
			d[x[I]] = fa[x[I]] = 0; dfs1(x[I]);
			int ans1 = lca(y[I], x[i]), ans2 = lca(y[I], y[i]);
			// cout << x[I] << " " << y[I] << " " << x[i] << " " << y[i] << " " << ans1 << " " << ans2 << endl;
			vector <int> path1 = getpath(ans1, ans2), path2, path3;
			if (check(getpath(ans1, x[i]), getpath(y[i], ans2))) path2 = merge(getpath(ans1, x[i]), getpath(y[i], ans2));
			else path2 = merge(getpath(ans1, y[i]), getpath(ans2, x[i]));
			if (check(getpath(ans1, x[I]), getpath(y[I], ans2))) path3 = merge(getpath(ans1, x[I]), getpath(y[I], ans2));
			else path3 = merge(getpath(ans1, y[I]), getpath(x[I], ans2));
			printf("YES\n");
			print(path1.size(), ' ');
			for (auto i : path1) print(i, ' ');
			putchar('\n');
			print(path2.size(), ' ');
			for (auto i : path2) print(i, ' ');
			putchar('\n');
			print(path3.size(), ' ');
			for (auto i : path3) print(i, ' ');
			putchar('\n');
			return 0;
		}
	}
	printf("NO\n");
    return 0;
}