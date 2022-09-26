#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		if (N > M) {
			cout << "No\n";
			continue;
		}
		if (N % 2 == 0) {
			if (M % 2) {
				cout << "No\n";
				continue;
			}
			cout << "Yes\n";
			for (int i = 0; i < N - 2; ++i) {
				cout << "1 ";
			}
			M -= (N - 2);
			cout << M / 2 << ' ' << M / 2 << '\n'; 
		} else {
			cout << "Yes\n";
			for (int i = 0; i < N - 1; ++i) cout << "1 ";
			cout << M - N + 1 << '\n';
		}
	}
	return 0;
}