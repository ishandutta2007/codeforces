#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<int64_t> A(N); for (auto &a : A) cin >> a;

	int64_t ans = 1e18;
	for (int s = 0; s < N; ++s) {
		int64_t cur = 0;
		int64_t v = 0;
		for (int i = s - 1; i >= 0; --i) {
			int64_t x = v / A[i] + 1;
			cur += x;
			v = x * A[i];
		}
		v = 0;
		for (int i = s + 1; i < N; ++i) {
			int64_t x = v / A[i] + 1;
			cur += x;
			v = x * A[i];
		}
		ans = min(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}