#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	vector<int> mins(n+1); // Minimum in suffix
	mins[n] = 9;
	for (int i = n-1; i >= 0; --i) {
		mins[i] = min(str[i] - '0', mins[i+1]);
	}

	bool fail = false;
	int cap = 10;
	int pre = 0;
	string res(n, '_');
	for (int i = 0; i < n; ++i) {
		int v = str[i] - '0';
		if (mins[i] == v && v <= cap) res[i] = '1';
		else {
			cap = min(cap, v);
			if (v < pre) fail = true;
			pre = v;
			res[i] = '2';
		}
	}
	if (fail) cout << "-" << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}