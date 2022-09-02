#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

const int N = 1e5;
vector<int> conns[N];
ll cst[N][3];
int ind[N];

void dfs(int i, int p, int v) {
	ind[i] = v;
	v = (v + 1) % 3;
	for (auto t : conns[i]) {
		if (t != p) dfs(t, i, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// All nodes must have degree 2, graph is a path, only 3 possibilities
	int n;
	cin >> n;
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < n; ++i) cin >> cst[i][j];
	}
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	int st = 0;
	bool fail = false;
	for (int i = 0; i < n; ++i) {
		if (conns[i].size() > 2) fail = true;
		if (conns[i].size() == 1) st = i;
	}
	if (fail) cout << "-1\n";
	else {
		dfs(st, -1, 0);
		ll ans = INF;
		int opt_j = -1;
		int opt_d = 0;
		for (int d = -1; d <= 1; d += 2) {
			for (int j = 0; j < 3; ++j) {
				ll off = 0;
				for (int i = 0; i < n; ++i) {
					int x = (3 + j + d*ind[i]) % 3;
					off += cst[i][x];
				}
				if (off < ans) {
					ans = off;
					opt_j = j;
					opt_d = d;
				}
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < n; ++i) {
			int x = (3 + opt_j + opt_d*ind[i]) % 3;
			cout << x+1 << ' ';
		}
		cout << '\n';
	}
}