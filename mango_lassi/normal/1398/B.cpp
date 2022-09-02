#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();

	vector<int> vals = {0};
	for (auto c : str) {
		if (c == '0') {
			if (vals.back() != 0) vals.push_back(0);
		} else {
			++vals.back();
		}
	}
	if (vals.back() == 0) vals.pop_back();

	sort(vals.begin(), vals.end());

	int res = 0;
	int m = vals.size();
	for (int i = m-1; i >= 0; i -= 2) res += vals[i];
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}