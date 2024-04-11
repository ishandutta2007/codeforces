#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	int pre = -1;
	vector<int> cou;
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		if (p == pre) ++cou.back();
		else cou.push_back(1);
		pre = p;
	}
	int m = cou.size();

	int go = cou[0];
	int si = 0;
	int br = 0;

	int j = 1;
	for (; j < m && si <= go; ++j) {
		si += cou[j];
	}
	for (; j < m; ++j) {
		if (2*(go + si + br + cou[j]) > n) break;
		br += cou[j];
	}

	if (br <= go) {
		cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
	} else {
		cout << go << ' ' << si << ' ' << br << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}