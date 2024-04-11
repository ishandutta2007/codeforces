#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
vector<int> adj[N];
vector<int> dvs[N];
int val[N], f[N], cnt[N];
int child[N];
bool visit[N];

void sieve() {
	for (int i = 1;i < N;++i) {
		for (int j = i;j < N;j += i) dvs[j].pb(i);
	}
}

void dfs(int u,int p) {
	child[u] = 1;
	for (int v : adj[u]) if (v != p && !visit[v]) {
		val[v] = __gcd(val[u], a[v]);
		dfs(v, u); child[u] += child[v];
	}
}

int find(int u,int p,int r) {
	for (int v : adj[u]) if (v != p && !visit[v]) {
		if (child[v] * 2 >= child[r]) return find(v, u, r);
	}
	return u;
}

void upd(int u,int p,int add) {
	for (int v : dvs[val[u]]) cnt[v] += add;
	for (int v : adj[u]) if (v != p && !visit[v]) {
		upd(v, u, add);
	}
}

void get(int u,int p) {
	for (int v : dvs[val[u]]) f[v] += cnt[v];
	for (int v : adj[u]) if (v != p && !visit[v]) {
		get(v, u);
	}
}

void centroid(int u) {
	dfs(u, u), u = find(u, u, u);
	visit[u] = true; val[u] = a[u];
	dfs(u, u);
	for (int v : dvs[val[u]]) cnt[v]++;
	for (int v : adj[u]) if (!visit[v]) {
		get(v, u), upd(v, u, 1);
	}
	for (int v : dvs[val[u]]) cnt[v]--;
	for (int v : adj[u]) if (!visit[v]) {
		upd(v, u, -1);
	}
	for (int v : adj[u]) if (!visit[v]) {
		centroid(v);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	sieve();
	cin >> n;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 0;i < n - 1;++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v), adj[v].pb(u);
	}
	centroid(1);
	for (int i = N - 1;i >= 1;--i) {
		for (int j = i + i;j < N;j += i) f[i] -= f[j];
	}
	for (int i = 1;i <= n;++i) f[a[i]]++;
	for (int i = 1;i < N;++i) {
		if (f[i]) cout << i << ' ' << f[i] << '\n';
	}
}