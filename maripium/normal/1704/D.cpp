#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int64_t> A(N);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int64_t b; cin >> b;
				A[i] += b * j;
			}
		}
		int K = max_element(A.begin(), A.end()) - A.begin();
		cout << K+1 << ' ' << A[K] - A[(K + 1) % N] << '\n';
	}
	return 0;	
}