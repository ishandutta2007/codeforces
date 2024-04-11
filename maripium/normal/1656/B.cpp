#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> A(N); for (int &a : A) cin >> a;
		sort(A.begin(), A.end());
		bool found = false;
		for (int i = 0; i < N; ++i) {
			if (binary_search(A.begin(), A.end(), A[i] - K)) {
				found = true;
				break;
			}
		}
		cout << (found ? "YES" : "NO") << '\n';
	}
	return 0;
}