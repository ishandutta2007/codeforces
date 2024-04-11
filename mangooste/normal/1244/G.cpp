#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline ll get(ll n) {
	return n * (n + 1) / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n, k;
	cin >> n >> k;

	if (k < get(n))
		return cout << "-1\n", 0;

	ll mx = 0;
	for (int i = n, j = 2 * n + 1; i; i--, j--)
		mx += j / 2;
	k = min(k, mx);

	cout << k << '\n';
	for (int i = 0; i < n; i++)
		cout << i + 1 << ' ';
	cout << '\n';

	ll need = k - get(n);
	vector<int> res(n);
	iota(res.begin(), res.end(), 1);

	int L = 0, R = n - 1;
	while (need) {
		if (need >= R - L) {
			need -= R - L;
			swap(res[L++], res[R--]);
		} else {
			swap(res[R], res[R - need]);
			need = 0;
		}
	}

	for (auto x : res)
		cout << x << ' ';
	cout << '\n';
}