#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		auto solve = [&]() -> vector<int> {
			if (N % 2) return {};
			sort(A.begin(), A.end());
			int M = N / 2;
			vector<int> ans;
			for (int i = 0; i < M; ++i) {
				ans.push_back(A[i]);
				ans.push_back(A[i + M]);
				if (i && A[i + M - 1] == A[i]) {
					return {};
				}
			}
			return ans;
		};
		auto ans = solve();
		if (ans.size()) {
			cout << "YES\n";
			for (int v : ans) cout << v << ' '; cout << '\n';
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}