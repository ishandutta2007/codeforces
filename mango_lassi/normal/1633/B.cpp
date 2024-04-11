#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;
	int n = str.size();
	int ones = 0;
	for (auto c : str) ones += (c == '1');
	int zeros = n - ones;

	if (ones == zeros) cout << ones - 1 << '\n';
	else cout << min(ones, zeros) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}