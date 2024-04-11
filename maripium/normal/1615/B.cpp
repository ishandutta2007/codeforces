#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	auto cnt = [&](int L, int B) {
		int ans = L >> (B + 1) << B;
		L %= (1 << (B + 1));
		if (L >= (1 << B)) ans += L - (1 << B);
		return ans;
	};
	while (T--) {
		int L, R; cin >> L >> R;
		int ans = 0;
		for (int b = 0; b < 20; ++b) {
			ans = max(ans, cnt(R + 1, b) - cnt(L, b));
		}
		cout << R - L + 1 - ans << '\n';
	}
	return 0;
}