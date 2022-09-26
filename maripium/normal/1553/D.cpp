#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
		string S, T; cin >> S >> T;
		bool ok = false;
		int N = int(S.size());
		int M = int(T.size());
                int z = (N + M) & 1;
			int cur = 0;
			for (int i = 0; i < N; ++i) {
				if (cur < M && S[i] == T[cur] && (i & 1) == ((cur ^ z) & 1)) {
					cur++;
				}
			}
			if (cur == M) ok = 1;
		cout << (ok ? "YES" : "NO") << '\n';
	}	
	return 0;
}