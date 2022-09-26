#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		sort(A.begin(), A.end());
		cout << A[N - 2] + A[N - 1] << '\n';
	}
}