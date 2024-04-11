#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto& pr : pts) cin >> pr.first >> pr.second;

	vector<ll> count(4, 0);
	for (int i = 0; i < n; ++i) {
		int a = (pts[i].first % 4) / 2;
		int b = (pts[i].second % 4) / 2; 
		++count[a + 2*b];
	}

	ll res = 0;
	for (int i = 0; i < 4; ++i) {
		res += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
		res += count[i] * (count[i] - 1) * (count[i ^ 3] + count[i ^ 1] + count[i ^ 2]) / 2;
	}
	cout << res << '\n';

	// Choose two endpoints
	// How many third endpoints work?

	// Area = interior + boundary / 2 - 1
	// interior = Area + 1 - boundary / 2
	// Area = (x0 y1 - x1 y0) + (x1 y2 - y1 x2) + (x2 y0 - y2 x0)
	// On boundary of (x0, y0), (x1, y1): gcd(x1 - x0, y1 - y0) -> even!

	// All coordinates even -> Area divisible by 4
	// odd number in interior IFF amount divisible by 4 in boundary
	// odd number in interior IFF either one pair or all pairs of points have amount divisible by 4

	// (x0 - x1) % 4 == 0
	// (x1 - x2) % 4 == 0
	// (x2 - x0) % 4 == 0
	// (y0 - y1) % 4 == 0
	// (y1 - y2) % 4 == 0
	// (y2 - y0) % 4 == 0
	// -> All of them have same (y, x) % 4

	// (x0 - x1) % 4 == 0
	// (x1 - x2) % 4 == 2
	// (x2 - x0) % 4 == 2
	// (y0 - y1) % 4 == 0
	// (y1 - y2) % 4 == 2
	// (y2 - y0) % 4 == 2
	// -> Two of them have same (y, x) % 4, one of them has a different one

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}