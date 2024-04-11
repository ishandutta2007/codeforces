#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)


const int N = 1e6 + 5;
int n, Q, r;
int dep[N], dis[N];
vector <int> E[N];

void dfs (int x, int fa = -1) {
	for (auto v : E[x]) if (v != fa) {
		dep[v] = dep[x] + 1;
		dfs (v, x);
	}
}

int X, ans;
vector <int> val[N];

void merge (vector <int> & u, vector <int> & v, int deplca) {
	if (v.size() > u.size()) swap(u, v);
	for (int i = 0; i < v.size(); i++) {
		int j = max(0, ans - X - i + 1);
		while (j < u.size() && u[j] + v[i] - 2 * deplca > ans) {
			ans ++;
			j = max(0, ans - X - i + 1);
		}
	}
	for (int i = 0; i < v.size(); i++) u[i] = max(u[i], v[i]);
}

void add_lca(vector <int> &u, int d, int de) {
	assert (d <= u.size());
	for (int j = max(0, ans - X - d + 1); j < u.size() && u[j] - de > ans; ans ++, j = max(0, ans - X - d + 1));
	if (d == u.size()) u.push_back(de);
	else u[d] = max(u[d], de);
}

void solve (int x, int fa = -1) {
	val[x].clear();
	for (auto v : E[x]) if (v != fa) {
		solve (v, x);
		merge (val[x], val[v], dep[x]);
	}
	add_lca(val[x], dis[x], dep[x]);
/*	
	cerr << "ans = " << ans << endl;
	cerr << x << " : " << val[x].size() << endl;
	for (auto i : val[x]) cerr << i << " ";
	cerr << endl;  */
}

void work() {
	read(X);
	ans = 0;
	solve (r);
	printf("%d\n", ans);
}

int main() {
	read(n);
	for (int i = 2; i <= n; i++) {
		int p; read(p);
		E[p].push_back(i);
		E[i].push_back(p);
	}
	fill(dis + 1, dis + n + 1, n);
	queue <int> q;
	for (int i = 1; i <= n; i++) if (E[i].size() == 1) dis[i] = 0, q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (auto v : E[x]) if (dis[v] == n) {
			dis[v] = dis[x] + 1;
			q.push(v);
		}
	}
	r = 1;
	while (E[r].size() == 1) r++;
	//cerr << "root = " << r << endl;
	dfs(r);
	read(Q);
	while (Q--) work();
}