#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5;
const int K = 1e5;
vector<int> conns[N + K];
bool visit[N + K];

int dfs(int i, bool s) {
	for (int j = 0; j < conns[i].size(); ++j) {
		int t = conns[i][j];
		if (visit[t]) {
			swap(conns[i][j], conns[i].back());
			conns[i].pop_back();
			--j;
		} else {
			visit[t] = true;
		}
	}

	int res = (s && conns[i].empty());
	for (auto t : conns[i]) res += dfs(t, !s);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<bool> used(n, false);

	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(i + n);
		conns[b].push_back(i + n);
		conns[i + n].push_back(a);
		conns[i + n].push_back(b);
	}
	int res = 0;
	for (int i = 0; i < k; ++i) {
		if (! visit[i + n]) {
			visit[i + n] = true;
			res += dfs(i + n, 1);
		}
	}
	cout << res << '\n';
}