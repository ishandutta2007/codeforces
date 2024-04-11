#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a, --a;
		vector<int> B(N); for (int &b : B) cin >> b, --b;
		auto solve = [&]() {
			int i = N - 1;
			int j = N - 1;
			vector<int> wait(N);
			while (i >= 0) {
				int v = A[i];
				while (i >= 0 && A[i] == v) wait[v]--, i--;
				while (j >= 0 && B[j] == v) wait[v]++, j--;
				if (wait[v] < 0) return false;
			}
			if (j > 0) return false;
			return true;
		};
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}