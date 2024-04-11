#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n;
string op[N];
int par[N];
vector<int> child[N];
int a[N], f[N][2];

void dfs(int u) {
	for (int v : child[u]) {
		dfs(v);
	} 
	if (op[u] == "IN") return;
	else if (op[u] == "NOT") {
		int v = child[u][0];
		a[u] = a[v] ^ 1;
		return;
	}
	int v = child[u][0], w = child[u][1];
	if (op[u] == "AND") a[u] = a[v] & a[w];
	else if (op[u] == "OR") a[u] = a[v] | a[w];
	else a[u] = a[v] ^ a[w];
}

int calc(int u,int k) {
	if (u == 1) return k;
	int &ret = f[u][k];
	if (~ret) return ret;
	int p = par[u];
	int nk = k;
	if (op[p] == "NOT") nk ^= 1;
	else {
		int v = child[p][0] ^ child[p][1] ^ u;
		if (op[p] == "AND") nk &= a[v];
		else if (op[p] == "OR") nk |= a[v];
		else nk ^= a[v];
	}	
	return ret = calc(p, nk);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> op[i];
		if (op[i] == "IN") cin >> a[i];
		else {
			if (op[i] == "NOT") {
				int u; cin >> u;
				par[u] = i, child[i].push_back(u);
			}
			else {
				int u, v; cin >> u >> v;
				par[u] = i, child[i].push_back(u);
				par[v] = i, child[i].push_back(v);
			}
		}
	}
	
	dfs(1); memset(f, -1, sizeof f);
	for (int i = 1; i <= n; ++i) if (op[i] == "IN") {
		cout << calc(i, a[i] ^ 1);
	}
	cout << '\n';
}