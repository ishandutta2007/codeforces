#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		int i = 0;
		int j = 0;
		for (int k = 0; k < N; ++k) {
			if (A[k] > A[i]) i = k;
			if (A[k] < A[j]) j = k;
		}
		cout << i + 1 << ' ' << j + 1 << '\n';
	}
	return 0;
}