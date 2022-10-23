#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, c;
	cin >> n >> c;

	vector<int> cou(101, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cou[a];
	}

	ll res = 0;
	for (int i = 1; i <= 100; ++i) res += min(c, cou[i]);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}