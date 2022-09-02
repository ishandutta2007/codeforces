#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
const int M = 2 * (int)1e5;
vector<int> res[M + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 0;; a /= 2, ++j) {
			res[a].push_back(j);
			if (a == 0) break;
		}
	}

	int ans = INF;
	for (int v = 0; v <= M; ++v) {
		sort(res[v].begin(), res[v].end());
		if (res[v].size() < k) continue;
		for (int i = 1; i < k; ++i) res[v][i] += res[v][i-1];
		ans = min(ans, res[v][k-1]);
	}
	cout << ans << '\n';
}