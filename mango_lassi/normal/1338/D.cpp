#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5;
vector<int> conns[N];
int dp[N][2];
int res = 0;

void dfs(int i, int p = -1) {
	int deg = conns[i].size();
	int kids = deg - (p != -1);

	int cb0 = 0;
	int cb1 = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		res = max(res, dp[t][0] + cb0 + (deg - 2));
		res = max(res, dp[t][0] + cb1);
		res = max(res, dp[t][1] + cb0 + (deg - 2));

		cb0 = max(cb0, max(dp[t][0], dp[t][1]));
		cb1 = max(cb1, dp[t][0] + 1);
	}
	dp[i][0] = max(0, cb0 + kids - 1);
	dp[i][1] = cb1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	dfs(0);
	cout << res << '\n';
}