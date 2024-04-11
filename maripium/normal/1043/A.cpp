#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	auto ok = [&](int mid) {
		int num = 0;
		for (int i = 0; i < n; ++i) {
			num += mid - 2 * a[i];
		}
		return num > 0;
	};
	int low = *max_element(a.begin(), a.end());
	int high = 1000;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (ok(mid)) high = mid;
		else low = mid + 1; 
	}
	cout << low << '\n';
}