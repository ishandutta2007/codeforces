#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int L, N; cin >> L >> N;
	vector<int> A(N); for (int &a : A) cin >> a;

	auto solve = [&](int s, int l) -> optional<vector<int>> {
		vector<pair<int, int>> ranges(N + 1);
		ranges[0] = make_pair(0, 0);
		for (int i = 0; i < N; ++i) {
			int a = A[i];
			int na = (i == N - 1 ? L : A[i + 1]);
			ranges[i + 1] = make_pair(ranges[i].first + s, ranges[i].second + l);
			if (ranges[i + 1].first > na) return nullopt;
			if (ranges[i + 1].second < a) return nullopt;
			ranges[i + 1].first = max(ranges[i + 1].first, a);
			ranges[i + 1].second = min(ranges[i + 1].second, na);
		}

		if (ranges[N].second < L) return nullopt;
		ranges[N] = make_pair(L, L);
		for (int i = N - 1; i >= 0; --i) {
			int a = A[i];
			int na = (i == 0 ? 0 : A[i - 1]);

			ranges[i].first = max(ranges[i].first, ranges[i + 1].first - l);
			ranges[i].second = min(ranges[i].second, ranges[i + 1].second - s);
		}

		vector<int> ans;
		for (int i = 0; i <= N; ++i) ans.push_back(ranges[i].first);
		return {ans};
	};

	int v0, v1;
	{
		int l = 1, r = L;
		while (l < r) {
			int md = (l + r) >> 1;
			if (solve(1, md).has_value()) r = md;
			else l = md + 1; 
		}
		v1 = l;
	}

	{
		int l = 1, r = L;
		while (l < r) {
			int md = (l + r + 1) >> 1;
			if (solve(md, L).has_value()) l = md;
			else r = md - 1;
		}
		v0 = l;
	}

	auto ans = solve(v0, v1).value();
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
	}
}