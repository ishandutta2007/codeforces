#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	int losses = 0;
	for (auto c : str) losses += (c == 'L');

	int cur = -(n+1);
	vector<int> gaps;
	ll res = 0;
	for (auto c : str) {
		if (c == 'L') {
			++cur;
		} else {
			res += 1 + (cur == 0);
			if (cur > 0) gaps.push_back(cur);
			cur = 0;
		}
	}
	sort(gaps.begin(), gaps.end());

	for (auto len : gaps) {
		if (k >= len) {
			k -= len;
			losses -= len;
			res += 2 * len + 1;
		}
	}
	res += 2 * min(k, losses) - (k > 0 && losses == n);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) solve();
	
}