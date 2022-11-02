#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll opt(ll n) {
	ll a = 1;
	ll b = 1;
	while (a + 2 * b < n) {
		b *= 2;
		a += b;
	}
	if (a + b < n) {
		return n - a;
	}
	return b;
}

vector<int> go(int m, int cnt) {
	assert(m > 0);
	if (m == 1) {
		return {};
	}
	int prev_m = m - cnt;
	int min_cnt = (cnt + 1) / 2;
	int prev_cnt = opt(prev_m);
	prev_cnt = max(prev_cnt, min_cnt);
	int add = cnt - prev_cnt;
	auto t = go(prev_m, prev_cnt);
	t.push_back(add);
	return t;
}


void solve() {
	int n;
	cin >> n;
	auto res = go(n, opt(n));
	cout << res.size() << "\n";
	for (int r : res) {
		cout << r << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
}