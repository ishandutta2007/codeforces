#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int N = 1e5;
vector<pair<int, int>> g[N];
int tag[N];
int dp[N][2]; // 0: no edge up, 1: edge up
int bestc[N];

int findCycles(int i, int p) {
	int res = tag[i];
	for (auto& pr : g[i]) {
		int t = pr.first;
		if (t == p) continue;

		if (tag[t] != -1) {
			pr.second = 1;
			res = min(res, tag[t]);
		} else {
			tag[t] = tag[i] + 1;
			int sub = findCycles(t, i);
			if (sub <= tag[i]) pr.second = 1;
			res = min(res, sub);
		}
	}
	if (res < tag[i]) {
		for (auto& pr : g[i]) {
			if (pr.first == p) pr.second = 1;
		}
	}
	return res;
}

void fillDP(int i, int p) {
	int cou = 0;
	dp[i][0] = 0;
	dp[i][1] = 0;
	bestc[i] = -1;

	pair<int, int> best = {0, -1};
	for (auto pr : g[i]) {
		int t = pr.first;
		if (pr.second || t == p) continue;
	
		++cou;
		fillDP(t, i);

		dp[i][0] += dp[t][1];
		best = min(best, {dp[t][0] - dp[t][1] - 1, t});
	}
	dp[i][0] += cou / 2;

	if (cou & 1) {
		if (p == -1) {
			dp[i][1] = dp[i][0] + best.first + 1;
			dp[i][0] = dp[i][0] + 1;
			bestc[i] = best.second;
		} else {
			dp[i][1] = dp[i][0];
			dp[i][0] = INF;
			bestc[i] = -1;
		}
	} else if (cou > 0) {
		dp[i][1] = dp[i][0] + best.first + (p == -1 && best.second != -1);
		bestc[i] = best.second;
	}
}

int recFill(int i, int p, bool eup, vector<pair<int, int>>& res) {
	int cur = -1;
	for (auto pr : g[i]) {
		int t = pr.first;
		if (pr.second || t == p) continue;

		if (eup && t == bestc[i]) recFill(t, i, 0, res);
		else {
			int sub = recFill(t, i, 1, res);
			if (cur != -1) {
				res.emplace_back(cur, sub);
				cur = -1;
			} else {
				cur = sub;
			}
		}
	}

	if (eup) {
		if (cur == -1) return i;
		else return cur;
	} else {
		if (cur != -1) res.emplace_back(i, cur);
		return -1;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0) exit(0);

	for (int i = 0; i < n; ++i) {
		tag[i] = -1;
		dp[i][0] = -1;
	}

	for (int j = 0; j < m; ++j) {
		int s;
		cin >> s;
		int a = -1;
		for (int i = 0; i < s; ++i) {
			int b;
			cin >> b;
			--b;

			if (a != -1) {
				g[a].emplace_back(b, 0);
				g[b].emplace_back(a, 0);
			}
			a = b;
		}
	}

	tag[0] = 0;
	findCycles(0, -1);

	vector<pair<int, int>> res;
	for (int i = 0; i < n; ++i) {
		if (dp[i][0] != -1) continue;
		fillDP(i, -1);

		if (dp[i][1] < dp[i][0]) recFill(i, -1, 1, res);
		else recFill(i, -1, 0, res);
	}

	cout << res.size() << '\n';
	for (auto pr : res) cout << pr.first + 1 << ' ' << pr.second + 1<< '\n';

	for (int i = 0; i < n; ++i) {
		g[i].clear();
		g[i].shrink_to_fit();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while(true) solve();
}