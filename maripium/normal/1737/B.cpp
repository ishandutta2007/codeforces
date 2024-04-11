#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);


	auto solve = [&](int64_t x) {
		// v * v
		int64_t ans = floor(sqrtl(x));
		// v * (v + 1);
		ans += ((floor(sqrtl(4 * x + 1))) - 1) / 2;
		ans += floor(sqrtl(x + 1)) - 1;
		return ans;
	};

	int T; cin >> T;
	while (T--) {
		int64_t l, r; cin >> l >> r;
		cout << solve(r) - solve(l - 1) << '\n';
	}
}