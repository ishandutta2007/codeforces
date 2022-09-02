#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

pair<ll, ll> diff(pair<ll, ll> a, pair<ll, ll> b) {
	return {a.first - b.first, a.second - b.second};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Given polygon, is its maximization similar with it?
	// IFF it is a mirroring of itself?


	int n;
	cin >> n;

	vector<pair<ll, ll>> pts(n);
	for (auto& pr : pts) cin >> pr.first >> pr.second;

	bool fail = false;
	if (n % 2 != 0) fail = true;
	else {
		int h = n/2;
		for (int i = 0; i < n; ++i) {
			auto pr1 = diff(pts[i], pts[(i+1)%n]);
			auto pr2 = diff(pts[(i+h)%n], pts[(i+h+1)%n]);
			if (pr1.first + pr2.first || pr1.second + pr2.second) fail = true;
		}
	}
	if (fail) cout << "NO\n";
	else cout << "YES\n";
}