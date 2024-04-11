#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> x(n);
	for (auto &el : x) {
		cin >> el;
	}
	int a, b;
	cin >> a >> b;
	set<pair<int, int>> can;
	for (auto &el : x) {
		if ((a / el) * el >= b) {
			can.insert({(a / el) * el, el});
		}
	}
	int ans = 0;
	for (int i = a; i > b; ans++) {
		i = (can.size() ? min(i - 1, can.begin()->first) : i - 1);
		while (can.size() && can.rbegin()->first > i) {
			pair<int, int> back = *can.rbegin();
			can.erase(--can.end());
			back.first -= ((back.first - i + back.second - 1) / back.second) * back.second;
			if (back.first >= b) {
				can.insert(back);
			}
		}
	}
	cout << ans;
}