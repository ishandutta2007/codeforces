#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll power(ll a, int b) {
	ll prod = 1;
	for (int i = 0; i < b; i++)
		prod *= a;
	return prod;
}

ll solve(int maxa, int maxb) {
	if (maxa > maxb)
		swap(maxa, maxb);
	if (maxa < 0)
		return 0;

	vector<int> ba(31), bb(31);
	for (int i = 0; i < 31; i++) {
		ba[i] = (maxa >> i) % 2;
		bb[i] = (maxb >> i) % 2;
	}

	reverse(ba.begin(), ba.end());
	reverse(bb.begin(), bb.end());
	ba.push_back(1);
	bb.push_back(1);

	// cout << "ba = ";
	// for (auto x : ba)
	// 	cout << x;
	// cout << "\nbb = ";
	// for (auto x : bb)
	// 	cout << x;
	// cout << '\n';

	ll ans = 0;
	for (int i = 0; i <= 31; i++)
		for (int j = 0; j <= 31; j++) {
			bool ok = true;
			for (int bit = 0; bit < min(i, j); bit++)
				ok &= (ba[bit] + bb[bit]) == (ba[bit] ^ bb[bit]);
			if (!ok)
				continue;

			if (!ba[i] || !bb[j])
				continue;

			int cnt = 0;
			for (int bit = min(i, j) + 1; bit < max(i, j); bit++)
				cnt += (i < j ? bb[bit] : ba[bit]) ^ 1;

			if (i != j && max(i, j) != 31)
				ans += (1ll << cnt + 1) * power(3, max(0, 31 - max(i, j) - 1));
			else
				ans += (1ll << cnt) * power(3, max(0, 31 - max(i, j) - 1));
		}

	return ans;
}

void solve() {
	int L, R;
	cin >> L >> R;
	cout << solve(R, R) - solve(L - 1, R) - solve(R, L - 1) + solve(L - 1, L - 1) << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}