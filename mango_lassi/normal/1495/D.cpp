#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int N = 400;
int dist[N][N];
vector<int> ord[N];
vector<int> g[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// Calculate all distances
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) dist[i][j] = MOD;
		dist[i][i] = 0;
		vector<int> que = {i};
		for (int j = 0; j < que.size(); ++j) {
			int x = que[j];
			for (auto t : g[x]) {
				if (dist[i][t] == MOD) {
					dist[i][t] = dist[i][x] + 1;
					que.push_back(t);
				}
			}
		}
		ord[i] = que;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int lst = -1;
			ll ways = 1;
			for (int ind = 0; ind < n; ++ind) {
				int x = ord[i][ind];
				if (dist[i][x] + dist[x][j] == dist[i][j]) {
					if (lst == dist[i][x]) ways = 0;
					else lst = dist[i][x];
				} else {
					ll picks = 0;
					for (int t : g[x]) {
						if (dist[i][t] == dist[i][x] - 1 && dist[j][t] == dist[j][x] - 1) ++picks;
					}
					ways = (ways * picks) % MOD;
				}
			}
			cout << ways << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}