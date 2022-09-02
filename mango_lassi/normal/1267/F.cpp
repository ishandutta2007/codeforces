#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> xs(x), ys(y);
	for (int& v : xs) cin >> v;
	for (int& v : ys) cin >> v;

	bool fail = (x >= m || y >= n);
	if (fail) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

	while(xs.size() < m-1) xs.push_back(n);
	while(ys.size() < n-1) ys.push_back(n+m);

	vector<int> cou(n+m, 0);
	for (auto v : xs) ++cou[v-1];
	for (auto v : ys) ++cou[v-1];

	priority_queue<int> que;
	for (int i = 0; i < n+m; ++i) {
		if (cou[i] == 0) que.push(-i);
	}

	int a = 0, b = 0;
	while(! que.empty()) {
		int i = -que.top();
		que.pop();
		if (i < n) {
			if (a < ys.size()) {
				int j = ys[a] - 1;
				++a;

				cout << i+1 << ' ' << j+1 << '\n';
				--cou[j];
				if (cou[j] == 0) que.push(-j);
			} else {
				cout << i+1 << ' ' << n+m << '\n';
			}
		} else {
			if (b < xs.size()) {
				int j = xs[b] - 1;
				++b;

				cout << i+1 << ' ' << j+1 << '\n';
				--cou[j];
				if (cou[j] == 0) que.push(-j);
			}
		}
	}

	// Always remove smallest index with no more appearances
	// Must not have x == m, as in this case last removed has index smaller than second-last
	// Possible as long as x < m
}