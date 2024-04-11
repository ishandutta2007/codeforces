#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n, d;
	cin >> n >> d;
	
	int res = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (i == 0) res += a;
		else {
			int cou = min(a, d / i);
			d -= cou * i;
			res += cou;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}