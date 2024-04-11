#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int N = 2e5 + 10;
int n, pa[N], used[N], d[N], cnt = 0;
vector<int> g[N];
deque<int> q;
int ans[N], tot = 0;

void DFS(int u, int fa) {
	if(used[u]) return;
	static queue<int> q;
	q.push(u);
	pa[u] = fa;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		ans[++tot] = u;
		used[u] = 1;
		for(int &v : g[u]) {
			if(v == pa[u] || used[v]) continue;
			q.push(v), pa[v] = u;
		}
	}
	return;
}

int dfs(int u, int fa) {
	int deg = (fa != 0);
	for(int &v : g[u]) {
		if(v == fa) continue;
		deg += dfs(v, u);
	}
//	cout << u <<" " << deg << endl;
	if(deg % 2 == 0) {
		DFS(u, fa);
		return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1, p; i <= n; i++) {
		cin >> p;
		if(p) g[i].push_back(p), g[p].push_back(i);
	}
	dfs(1, 0);
	if(tot < n) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(d[ans[i]] % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
		d[ans[i]] = 0;
		for(int &v : g[ans[i]]) {
			d[v]--;
		}
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}