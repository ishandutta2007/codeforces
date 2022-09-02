#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());

	int m = n / 2;
	long long res = 0;
	for (int i = m; i >= 0; --i) {
		if (vals[i] >= s) {
			res += vals[i] - s;
			vals[i] = s;
		}
	}
	for (int i = m; i < n; ++i) {
		if (vals[i] <= s) {
			res += s - vals[i];
			vals[i] = s;
		}
	}
	cout << res << '\n';
}