#include <bits/stdc++.h>
using namespace std;

int n;
int k;
vector<int> max_cnt;
vector<int> a;

vector<vector<int>> solve(int cnt) {
	if (cnt == 0) {
		return {};
	}
	vector<vector<int>> res(cnt);
	for (int i = 0; i < n; i++) {
		int max_cur_size = max_cnt[a[i] - 1] - 1;
		auto it = lower_bound(res.begin(), res.end(), max_cur_size, [](const auto& a, int sz) {
			return a.size() > sz;
		});
		if (it == res.end()) {
			return {};
		}
		it->push_back(a[i]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	a.resize(n);
	max_cnt.resize(k);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	for (int i = 0; i < k; i++) {
		cin >> max_cnt[i];
	}
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (solve(m).empty()) {
			l = m;
		} else {
			r = m;
		}
	}
	auto res = solve(r);
	cout << r << "\n";
	for (const auto& row : res) {
		cout << row.size() <<  " ";
		for (int x : row) {
			cout << x << " ";
		}
		cout << "\n";
	}
}