#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	ll s = accumulate(a.begin(), a.end(), 0ll);
	for (int i = 0; i < n; i++)
		cout << s / n + (i < s % n) + i << ' ';
	cout << '\n';
}