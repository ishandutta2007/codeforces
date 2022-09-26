#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
		
	int T; cin >> T;
	while (T--) {
		int N, C; cin >> N >> C;
		vector<int> A(N); for (int &a : A) cin >> a;

		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		N = int(A.size());
		
		vector<int> cnt(C + 1);
		for (int a : A) cnt[a] ++;
		for (int i = 1; i <= C; ++i) cnt[i] += cnt[i - 1];

		vector<int> num_cover(C + 1);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (int64_t(A[i]) * A[j] > C) break;
				int l = A[i] * A[j];
				num_cover[l] ++;
				int r = min(A[i] * (A[j] + 1), C + 1);
				if (r <= C) num_cover[r] --;
			}
		}
		for (int i = 1; i <= C; ++i) num_cover[i] += num_cover[i - 1];
		
		bool fail = false;
		for (int i = 0; i < N; ++i) {
			if (num_cover[A[i]] < i + 1) {
				fail = true;
				break;
			}
		}

		cout << (fail ? "No" : "Yes") << '\n';
	}
	return 0;
}