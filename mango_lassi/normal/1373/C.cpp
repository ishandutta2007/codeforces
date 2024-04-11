#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	string str;
	cin >> str;

	int n = str.size();
	ll res = n, cur = 0, minv = 0;
	for (int i = 0; i < n; ++i) {
		cur += (str[i] == '+' ? 1 : -1);
		if (cur < minv) {
			res += i+1;
			minv = cur;
		}
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