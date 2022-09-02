#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, x;
	cin >> n >> x;

	int sum = 0;
	vector<int> vals(n);
	for (int& v : vals) {
		cin >> v;
		sum += v;
	}

	if (sum == x) {
		cout << "NO\n";
	} else {
		cout << "YES\n";

		int cur = 0;
		sort(vals.begin(), vals.end());
		for (int j = 0; j < vals.size(); ++j) {
			if (cur + vals[j] == x) {
				swap(vals[j], vals.back());
			}
			cur += vals[j];
			cout << vals[j] << ' ';
		}
		cout << '\n';
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}