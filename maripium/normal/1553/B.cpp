#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
	[&]() {
		string S, T; cin >> S >> T;
		int N = int(S.size());
		int M = int(T.size());
		for (int st = 0; st < N; ++st) {
			for (int r = 0; r < N - st; ++r) {
				int cur = st + r;
				int l = M - (r + 1);
				if (l < 0 || l > cur) continue;
				string Z;
				for (int i = 0; i <= r; ++i) Z += S[i + st];
				for (int i = 1; i <= l; ++i) Z += S[cur - i];
				if (Z == T) {
					cout << "YES\n";
					return;
				}
			}
		}		
		cout << "NO\n";
	}();
	}	
	return 0;
}