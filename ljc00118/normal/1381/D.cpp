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
 
const int N = 1e5 + 5;
 
vector <int> adj[N];
int dep[N], seq[N], fa[N];
int T, n, len, ans, x, y;
 
void dfs1(int u, int fa) {
	dep[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		dfs1(v, u);
		dep[u] = max(dep[u], dep[v] + 1);
	}
}
 
void chkdfs(int u, int fa) {
	int cnt = 0;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		chkdfs(v, u);
		if (dep[v] + 1 >= len) ++cnt;
	}
	if (cnt >= 2) ans = 1;
}
 
void dfs2(int u, int fa) {
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		::fa[v] = u;
		dfs2(v, u);
	}
}

void dfs3(int u, int fa, int mxdep) {
	int mx1 = mxdep + 1, mx2 = 0, cnt = 0;
	if (mxdep + 1 >= len) ++cnt;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		if (dep[v] + 1 >= len) ++cnt;
		if (dep[v] + 1 > mx1) mx2 = mx1, mx1 = dep[v] + 1;
		else if (dep[v] + 1 > mx2) mx2 = dep[v] + 1;
	}
	if (cnt >= 3) ans = 1;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		if (dep[v] + 1 == mx1) dfs3(v, u, mx2);
		else dfs3(v, u, mx1);
	}
}
 
int maxdep[N], ok[N];
int solve() {
	for (int i = 1; i <= len; i++) {
		int u = seq[i], cnt = 0;
		maxdep[i] = ok[i] = 0;
		for (int j = 0; j < (int)adj[u].size(); j++) {
			int v = adj[u][j];
			if (v == seq[i - 1] || v == seq[i + 1]) continue;
			dfs1(v, u); ans = 0; chkdfs(v, u);
			if (ans) ok[i] = 1;
			if (dep[v] + 1 >= len) ++cnt;
			maxdep[i] = max(maxdep[i], dep[v] + 1);
		}
		if (cnt >= 2) ok[i] = 1;
	}
	if (ok[1] || ok[len]) return 1;
	int l = 1, r = len, pos_l = 1 + min(len - 1, maxdep[len] - 1), pos_r = len - min(len - 1, maxdep[1] - 1);
	while (1) {
		if (r > pos_r) {
			while (r > pos_r) {
				--r;
				pos_l = max(pos_l, r - (len - min(len - 1, maxdep[r] - 1)) + 1);
			}
			continue;
		}
		if (l < pos_l) {
			while (l < pos_l) {
				++l;
				pos_r = min(pos_r, l + (len - min(len - 1, maxdep[l] - 1)) - 1);
			}
			continue;
		}
		break;
	}
	ans = 0;
	if (l >= r) {
		dfs1(1, 0); dfs3(1, 0, 0);
	} else {
		// fprintf(stderr, "%d %d %d %d\n", seq[l], seq[l + 1], seq[r], seq[r - 1]);
		dfs1(seq[l], seq[l + 1]); chkdfs(seq[l], seq[l + 1]);
		dfs1(seq[r], seq[r - 1]); chkdfs(seq[r], seq[r - 1]);
	}
	return ans;
}
 
int main() {
	read(T);
	while (T--) {
		read(n); read(x); read(y);
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v;
			read(u); read(v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs2(y, 0);
		int tmp = x;
		len = ans = 0;
		while (tmp != y) {
			seq[++len] = tmp;
			tmp = fa[tmp];
		}
		seq[++len] = y; seq[len + 1] = 0;
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}