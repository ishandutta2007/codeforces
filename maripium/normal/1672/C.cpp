#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		int l = N, r = -1;
		for (int i = 0; i + 1 < N; ++i) {
			if (A[i] == A[i + 1]) {
				l = min(l, i);
				r = max(r, i);
			}
		}

		if (l >= r) {
			cout << "0\n";
		} else {
			cout << max(1, r - l - 1) << '\n';
		}
	}
	return 0;
}