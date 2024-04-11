#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	map<int, int> cnt;
	int n, p, k;
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		cnt[x * (x * x % p * x % p - k + p) % p]++;
	}
	ll ans = 0;
	for (auto [_, num] : cnt)
		ans += num * (num - 1) / 2;
	cout << ans << '\n';
}