#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	string str;
	cin >> str;

	vector<int> vals(n+1, 0);
	for (int i = 1; i <= n; ++i) vals[i] = (str[i-1] - '0') + vals[i-1] - 1;

	// vals[i] == vals[i + k] <-> \sum_{j = i+1}^{i+k} str[j] == k

	sort(vals.begin(), vals.end());

	ll res = 0;
	for (int i = 0; i <= n;) {
		int j = i;
		while(j <= n && vals[j] == vals[i]) ++j;

		ll d = (j - i);
		res += (ll)d * (d-1) / 2;
		i += d;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}