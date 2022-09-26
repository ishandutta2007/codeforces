#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int64_t N; cin >> N;
		int64_t A = 2;
		int64_t B = N;
		while (B % 2 == 0) {
			A *= 2;
			B /= 2;
		}

		// A * B = 2 * N
		// min(A * (A + 1) / 2, B * (B + 1) / 2) <= AB / 2 = N
		if (B == 1) {
			cout << "-1\n";
		} else {
			cout << min(A, B) << '\n';
		}
	}	
}