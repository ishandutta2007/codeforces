#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int ans = 10;
		for (int z = 0; z < 2; ++z) {
			int t0 = 5, t1 = 5;
			int s0 = 0, s1 = 0;
			for (int i = 0; i < 10; ++i) {
				if ((i & 1) == z) {
					if (S[i] == '1' || S[i] == '?') s0++;
					t0--; 
				} else {
					if (S[i] == '1') s1++;
					t1--;
				}
				if (s1 + t1 < s0) {
					ans = min(ans, i + 1);
					break;
				}
			}
		}
		cout << ans << '\n';
	}	
	return 0;
}