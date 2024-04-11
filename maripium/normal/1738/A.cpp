#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		vector<int> B(N); for (int &a : B) cin >> a;

		vector<int> B0, B1;
		for (int i = 0; i < N; ++i) {
			if (A[i] == 0) {
				B0.push_back(B[i]);
			} else {
				B1.push_back(B[i]);
			}
		}
		sort(B0.begin(), B0.end(), greater<int>());
		sort(B1.begin(), B1.end(), greater<int>());
		int64_t ans = 0;
		if (B0.size() == B1.size()) {
			for (int i = 0; i < N; ++i) ans += 2 * B[i];
			ans -= min(B0.back(), B1.back());
		} else {
			if (B0.size() > B1.size()) swap(B0, B1);
			for (int i = 0; i < N; ++i) ans += B[i];
			for (int i = 0; i < int(B0.size()); ++i) {
				ans += B0[i];
				ans += B1[i];
			} 
		}
		cout << ans << '\n';
	}
	return 0;
}