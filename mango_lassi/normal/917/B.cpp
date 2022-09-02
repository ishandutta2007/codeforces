#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int C = 30;
const int N = 100;
int dp[N][N][C];
vector<pair<int, int>> edges[N];

int solve(int a, int b, int c) {
	if (dp[a][b][c] != 0) return dp[a][b][c];
	int res = -1;
	for (auto p : edges[a]) {
		if (c <= p.second) {
			if (solve(b, p.first, p.second) == -1) {
				res = 1;
			}
		}
	}
	dp[a][b][c] = res;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v, u;
		char c;
		cin >> v >> u >> c;
		--v; --u;
		edges[v].push_back({u, c-'a'});
	}
	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			if (solve(a, b, 0) == 1) {
				cout << "A";
			} else {
				cout << "B";
			}
		}
		cout << '\n';
	}
}