#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> as(n);
	vector<int> cou(n, 0);

	int res = n+1;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];
		++cou[as[i]];
		if (cou[as[i]] == 2) {
			while(true) {
				--cou[as[j]];
				++j;
				if (as[j-1] == as[i]) break;
			}
			res = min(res, i - j + 2);
		}
	}
	if (res > n) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}