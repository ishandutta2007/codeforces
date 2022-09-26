#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> A(M); 
		for (int i = 0; i < M; ++i) cin >> A[i], --A[i];
		sort(A.begin(), A.end());
		vector<int> L;
		auto add = [&](int v) {
			L.push_back(v);
		};
		for (int i = 0; i < M - 1; ++i) add(A[i + 1] - A[i] - 1);
		add(A[0] + N - A[M - 1] - 1);
		sort(L.begin(), L.end(), greater<int>());
		int ans = M;
		int days = 0;
		for (int i = 0; i < M; ++i) {
			ans += min(2 * days, L[i]);
			int left = L[i] - 2 * days;
			if (left <= 0) continue;
			days++;
			left--; // protect a house
			if (left) {
				ans++;
				left--;
				// infected 
			}
			if (left) {
				days++;
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}