#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		vector<int> A(N); 
		int64_t ans = 0;
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
			ans += A[i];
			A[i] += i;
		}
		sort(A.begin(), A.end(), greater<int>());
		for (int i = 0; i < K; ++i) {
			ans -= A[i];
			ans += (N - i - 1);
		}
		cout << ans << '\n';		
	}
	return 0;
}