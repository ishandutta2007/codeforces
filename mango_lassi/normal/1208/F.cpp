#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 1e6;
const int V = 1<<21;
int val[N];
int cou[V];
int ind[V];

void bfs(int v, int i) {
	if (ind[v] == i || cou[v] >= 2) return;
	cou[v] += 1;
	ind[v] = i;
	for (int j = 0; (1<<j) <= v; ++j) {
		if (v & (1<<j)) bfs(v ^ (1<<j), i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> val[i];
	for (int v = 0; v < V; ++v) ind[v] = n;
	for (int i = n-1; i >= 0; --i) {
		bfs(val[i], i);
	}
	int res = 0;
	for (int i = 0; i+2 < n; ++i) {
		int mask = 0;
		for (int j = 20; j >= 0; --j) {
			if (val[i] & (1<<j)) continue;
			int off = mask | (1<<j);
			if (cou[off] >= 2 && ind[off] > i) mask = off;
		}
		res = max(res, mask | val[i]);
	}
	cout << res << '\n';
}