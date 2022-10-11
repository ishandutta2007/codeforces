#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a)
		cin >> x;
	long long cnt = 0;
	int x = 0;
	vector<int> where(n, 0);
	for (int bit = 31; bit >= 0; bit--) {
		array<long long, 2> cur_cnt{0ll, 0ll};
		auto solve = [&](vector<int> &now) {
			int sz = (int) now.size();
			if (sz <= 1)
				return;
			vector<int> all;
			for (auto pos : now)
				all.push_back((a[pos] >> bit) % 2);
			vector<int> sum(sz + 1, 0);
			for (int i = 0; i < sz; i++)
				sum[i + 1] = sum[i] + all[i];
			for (int i = 1; i < sz; i++) {
				if (all[i] == 1)
					cur_cnt[1] += i - sum[i];
				else
					cur_cnt[0] += sum[i];
			}
		};
		vector<int> inds(n);
		iota(inds.begin(), inds.end(), 0);
		sort(inds.begin(), inds.end(), [&](int i, int j) {
			return where[i] < where[j] || (where[i] == where[j] && i < j);
		});
		vector<int> now{inds[0]};
		for (int i = 1; i < n; i++) {
			if (where[inds[i]] == where[inds[i - 1]])
				now.push_back(inds[i]);
			else {
				solve(now);
				now = {inds[i]};
			}
		}
		solve(now);
		if (cur_cnt[0] > cur_cnt[1])
			x += (1 << bit);
		cnt += min(cur_cnt[0], cur_cnt[1]);
		for (int i = 0; i < n; i++)
			where[i] += (a[i] & (1 << bit));
	}
	cout << cnt << ' ' << x << '\n';
}