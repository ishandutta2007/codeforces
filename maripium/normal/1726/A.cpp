#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		int ans = -1000;
		for (int i = 0; i < N; ++i) {
			ans = max(ans, A[i] - A[(i + 1) % N]);
		}
		for (int i = 0; i < N; ++i) {
			if (i) ans = max(ans, A[i] - A[0]);
			if (i + 1 < N) ans = max(ans, A[N - 1] - A[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}