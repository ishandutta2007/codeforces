#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;

	while (T--) {
		int A, B; cin >> A >> B;
		set<int> ans;
		for (int z = 0; z < 2; ++z) {
			int N = A + B;
			int A0 = (N + 1) / 2;
			int B0 = N / 2;
			for (int a = 0; a <= B0; ++a) {
				// break of A
				int b = A - a; // non break of A
				int c = B0 - a; // non break of B
				int d = B - c; // break of B
				if (b < 0 || d < 0) continue;
				ans.insert(a + d);
			}
			swap(A, B);
		}
		cout << int(ans.size()) << '\n';
		for (int v : ans) cout << v << ' '; cout << '\n';
	}
}