/**/
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define pi pair<int, int>
#define x first
#define y second
#define i64 long long
#define u64 unsigned long long
#define rep(x, L, R) for(int x = L, _x = R; x <= _x; x++)
using namespace std;
const int N = 4e5 + 10;
int n;
vector<int> g[N];
int sze[N], mx[N], pa[N];
int a[N], b[N], c[N], tot = 0;
void findc(int u, int fa, int all, int &c) {
	mx[u] = 0, sze[u] = 1;
	for(int v : g[u]) {
		if(v == fa) continue;
		findc(v, u, all, c);
		sze[u] += sze[v];
		mx[u] = max(mx[u], sze[v]);
	}
	mx[u] = max(mx[u], all - sze[u]);
	if(c == -1 || mx[c] > mx[u]) {
		c = u;
	}
	return;
}

void dfs(int u, int fa, vector<int> &id) {
	pa[u] = fa;
	id.push_back(u);
	for(int v : g[u]) {
		if(v == fa) continue;
		dfs(v, u, id);
	}
	return;
}

void solve(int rt, int fa) {
	for(int v : g[rt]) {
		if(v == fa) continue;
		vector<int> son;
		dfs(v, rt, son);
		int now = v;
		for(int i = 1; i < sz(son); i++) {
			a[++tot] = rt, b[tot] = now, c[tot] = son[i];
			now = son[i];
			a[++tot] = son[i], b[tot] = pa[son[i]], c[tot] = v;
		}
		a[++tot] = rt, b[tot] = now, c[tot] = v;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int rt = -1;
	findc(1, 0, n, rt);
	if(mx[rt] * 2 < n) {
		solve(rt, 0);
	} else {
		int rt1 = rt, rt2 = -1;
		for(int v : g[rt]) {
			if(mx[v] * 2 == n) {
				rt2 = v;
			}
		}
		solve(rt1, rt2), solve(rt2, rt1);
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << a[i] <<" " << b[i] <<" " << c[i] << endl;
	return 0;
}