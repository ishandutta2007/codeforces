#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string str;
	cin >> str;

	int res = n;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') res = max(res, max(2*n - 2*i, 2*(i+1)));
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