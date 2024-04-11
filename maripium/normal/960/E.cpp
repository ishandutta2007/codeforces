#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N];
vector<int> adj[N];
int child[N];
bool visit[N];
int dist[N], high[N];
int f[2], cnt[2];
int res = 0;
void dfs(int u,int p) {
	child[u] = 1;
	for (int v : adj[u]) if (v != p && !visit[v]) {
		dfs(v, u); child[u] += child[v];
	}
}

int find(int u,int p,int r) {
	for (int v : adj[u]) if (v != p && !visit[v]) {
		if (child[v] * 2 >= child[r]) return find(v, u, r);
	}
	return u;
}

void pre(int u,int p) {
	for (int v : adj[u]) if (v != p && !visit[v]) {
		high[v] = high[u] + 1;
		if (high[v] & 1) dist[v] = (dist[u] - a[v] + MOD) % MOD;
		else dist[v] = (dist[u] + a[v]) % MOD;
		pre(v, u);	
	}
}

void upd(int u,int p) {
	int hu = high[u] & 1;
	f[hu] = (f[hu] + dist[u]) % MOD, cnt[hu]++;
	for (int v : adj[u]) if (v != p && !visit[v]) {
		upd(v, u);
	}
}

void get(int u,int p,int r) {
	int hu = high[u] & 1;
	int du = (dist[u] - a[r] + MOD) % MOD;
	int val = (1LL * cnt[hu] * du + f[hu]) % MOD;
	if (hu) res = (res - val + MOD) % MOD;
	else res = (res + val) % MOD;
	for (int v : adj[u]) if (v != p && !visit[v]) {
		get(v, u, r);
	}
}

void centroid(int u) {
	dfs(u, u), u = find(u, u, u), visit[u] = true;
	dist[u] = a[u], high[u] = 0, pre(u, u);
	f[1] = cnt[1] = 0;
	f[0] = a[u], cnt[0] = 1;
	for (int v : adj[u]) if (!visit[v]) {
		get(v, u, u), upd(v, u);
	}
	for (int v : adj[u]) if (!visit[v]) {
		centroid(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		if (a[i] < 0) a[i] += MOD;
	}
	for (int i = 0;i < n - 1;++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	centroid(1);
	res = res * 2 % MOD;
	for (int i = 1;i <= n;++i) res = (res + a[i]) % MOD;
	cout << res << endl;
}