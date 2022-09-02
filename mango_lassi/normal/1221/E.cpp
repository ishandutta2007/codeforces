#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

bool solve() {
	int a, b;
	cin >> a >> b; // b < a
	string str;
	cin >> str;
	int n = str.size();

	vector<int> lens;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '.') {
			if (i == 0 || str[i-1] == 'X') lens.push_back(1);
			else ++lens.back();
		}
	}
	sort(lens.begin(), lens.end());
	int m = lens.size();

	if (m >= 2 && lens[m-2] >= 2*b) return false;
	for (auto v : lens) {
		if (b <= v && v < a) return false;
	}

	int cou = 0;
	for (auto v : lens) {
		if (b <= v && v < a + b) ++cou;
	}
	if (m >= 1 && lens[m-1] >= a + b) {
		// loop splits
		for (int j = 0; j + a <= lens[m-1]; ++j) {
			int r = lens[m-1] - (j + a);
			if (r >= 2*b || j >= 2*b) continue;
			if (b <= r && r < a || b <= j && j < a) continue;
			int off = 1 + (r >= a) + (j >= a);
			if ((cou + off) & 1) return true;
		}
		return false;
	} else {
		return cou & 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		bool res = solve();
		if (res) cout << "YES\n";
		else cout << "NO\n";
	}
}