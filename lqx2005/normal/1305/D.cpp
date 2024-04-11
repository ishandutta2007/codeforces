#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int N = 1e3 + 10;
vector<int> g[N];
int deg[N];

int ask(int u, int v) {
	cout << "? " << u <<" " << v << endl;
	int lca;
	cin >> lca;
	return lca;
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].eb(v), g[v].eb(u);
		deg[u]++, deg[v]++;
	}
	for(; ; ) {
		vector<int> l;
		for(int i = 1; i <= n; i++) if(0 <= deg[i] && deg[i] <= 1) l.eb(i);
		if(sz(l) == 1) {
			cout << "! " << l[0] << endl;
			return;
		}
		int u = l[0], v = l[1];
		int lca = ask(u, v);
		if(lca == u) {
			cout << "! " << u << endl;
			return;
		}
		if(lca == v) {
			cout << "! " << v << endl; 
			return;
		}
		deg[u] = deg[v] = -1;
		for(int w : g[u]) if(deg[w] > 0) deg[w]--;
		for(int w : g[v]) if(deg[w] > 0) deg[w]--;
	}
	return;
}

int main() {
	solve();
	return 0;
}