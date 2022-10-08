#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> A(K); for (int &a : A) cin >> a;

		bool fail = false;
		int last = 2.02e9;
		for (int i = K - 1; i > 0; --i) {
			int cur = A[i] - A[i - 1];
			if (cur > last) {
				fail = true;
				break;
			}
			last = cur;
		}
		if (int64_t(last) * (N - K + 1) < A[0]) fail = true;
		if (fail) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
	return 0;
}