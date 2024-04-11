#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Operation is x ^ (x & y). Answer is bits in a1 minus bits in any of the other numbers

	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];

	vector<int> pref(n+1, 0), suff(n+1, 0);
	for (int i = 0; i < n; ++i) {
		pref[i+1] = pref[i] | vals[i];
		suff[n-i-1] = suff[n-i] | vals[n-i-1];
	}

	pair<int, int> res = {-1, -1};
	for (int i = 0; i < n; ++i) {
		int x = vals[i];
		int y = pref[i] | suff[i+1];
		res = max(res, {x ^ (x & y), i});
	}

	int i = res.second;
	cout << vals[i] << ' ';
	for (int j = 0; j < n; ++j) {
		if (j == i) continue;
		cout << vals[j] << ' ';
	}
	cout << '\n';
}