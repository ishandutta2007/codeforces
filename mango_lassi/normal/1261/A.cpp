#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void inv(int a, int b, string& str, vector<pair<int, int>>& ops) {
	ops.push_back({a+1, b+1});
	for (int i = 0; a+i < b-i; ++i) swap(str[a+i], str[b-i]);
}

void solve() {
	int n, k;
	cin >> n >> k;

	string str;
	cin >> str;

	vector<pair<int, int>> ops;
	while(k > 1) {
		if (str[n-2] == '(' && str[n-1] == ')') {
			n -= 2;
			--k;
			continue;
		}

		int i = 0;
		for (; i+1 < n; ++i) {
			if (str[i] == '(' && str[i+1] == ')') {
				break;
			}
		}
		if (i+1 < n) {
			inv(0, i+1, str, ops);
			inv(0, n-1, str, ops);
			n -= 2;
			--k;
		} else {
			inv(0, n-1, str, ops);
			inv(0, n-2, str, ops);
			n -= 2;
			--k;
		}
	}
	while(true) {
		int cou = 0;
		for (int i = n-1; i >= 0; --i) {
			if (str[i] == ')') ++cou;
			else break;
		}

		if (cou >= n/2) break;

		for (int i = 0; i < n-cou; ++i) {
			if (str[i] == ')') {
				if (i > 0) inv(0, i, str, ops);
				inv(0, n-cou-1, str, ops);
				break;
			}
		}
	}

	cout << ops.size() << '\n';
	for (auto pr : ops) cout << pr.first << ' ' << pr.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}