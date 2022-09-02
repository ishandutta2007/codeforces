#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<ll, int>> cans(n);
	for (int i = 0; i < n; ++i) {
		cin >> cans[i].first;
		cans[i].second = i + 1;
	}
	sort(cans.begin(), cans.end());
	reverse(cans.begin(), cans.end());

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += cans[i].first * i + 1;
	}

	cout << res << '\n';
	for (auto pr : cans) cout << pr.second << ' '; cout << '\n';
}