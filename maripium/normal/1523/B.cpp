#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a;
		cout << 3 * N << '\n';
		for (int i = 0; i < N; i += 2) {
			for (int t : {1, 2, 1, 1, 2, 1}) {
				cout << t << ' ' << i + 1 << ' ' << i + 2 << '\n';
			}
		}
	}
	return 0;
}