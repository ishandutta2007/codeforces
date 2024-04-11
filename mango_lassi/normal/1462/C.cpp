#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int X = 50;
string ans[X+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int x = 0; x <= X; ++x) ans[x] = "-1";

	for (int mask = 0; mask < (1 << 9); ++mask) {
		int sum = 0;
		string off;
		for (int j = 0; j < 9; ++j) {
			if (mask & (1 << j)) {
				sum += j + 1;
				off.push_back('1' + j);
			}
		}
		if (sum <= X) {
			bool rep = (ans[sum] == "-1");
			rep |= (off.size() < ans[sum].size());
			rep |= (off.size() == ans[sum].size() && ans[sum] > off);
			if (rep) ans[sum] = off;
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int x;
		cin >> x;
		cout << ans[x] << '\n';
	}
}