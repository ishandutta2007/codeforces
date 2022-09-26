#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<string> A(N);
		for (int i = 0; i < N; ++i) cin >> A[i];
		char a = 'R', b = 'W';
		for (int z = 0; z < 2; ++z, swap(a, b)) {
			vector<string> B(N, string(M, '~'));
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (i + j & 1) {
						B[i][j] = a;
					} else {
						B[i][j] = b;
					}
					if (A[i][j] != '.' && A[i][j] != B[i][j]) goto bad;
				}
			}
			cout << "YES\n";
			for (int i = 0; i < N; ++i) cout << B[i] << '\n';
			goto good;
bad:;
		}
		cout << "NO\n";
good:;
	}
	return 0;
}