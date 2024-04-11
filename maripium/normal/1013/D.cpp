#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;

int n, m, q;
int par[N];

int anc(int u) { return par[u] == u ? u : par[u] = anc(par[u]); }
void join(int u,int v) {
	par[anc(v)] = anc(u);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= n + m; ++i) par[i] = i;
	while (q--) {
		int x, y; cin >> x >> y;
		join(x, n + y);
	}
	int cnt = -1;
	for (int i = 1; i <= n + m; ++i) {
		cnt += anc(i) == i;
	}
	cout << cnt << '\n';
}