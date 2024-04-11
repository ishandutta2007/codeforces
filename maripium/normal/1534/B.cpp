#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N + 2);
		for (int i = 1; i <= N; ++i) cin >> A[i];
		int64_t tot = 0;
		for (int i = 0; i <= N; ++i) tot += abs(A[i] - A[i + 1]);
		for (int i = 1; i <= N; ++i) {
			if (A[i] > max(A[i - 1], A[i + 1])) tot -= A[i] - max(A[i - 1], A[i + 1]);
		}
		cout << tot << '\n';
	}
	return 0;
}