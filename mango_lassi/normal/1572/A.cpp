#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void solve() {
	int n;
	cin >> n;

	Graph g(n);
	vector<int> cou(n, 0);

	priority_queue<int> que;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		cou[i] = k;
		for (int j = 0; j < k; ++j) {
			int t;
			cin >> t;
			g[t - 1].push_back(i);
		}
		if (k == 0) que.push(-i);
	}

	int res = 0, tot = 0;
	priority_queue<int> nxt;
	for (; !que.empty(); ++res) {
		while(! que.empty()) {
			int i = -que.top();
			que.pop();
			++tot;

			for (int t : g[i]) {
				--cou[t];
				if (cou[t] == 0) {
					if (t < i) nxt.push(-t);
					else que.push(-t);
				}
			}
		}
		swap(que, nxt);
	}

	if (tot == n) {
		cout << res << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}