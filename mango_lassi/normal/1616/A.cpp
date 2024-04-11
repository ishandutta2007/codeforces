#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> cou(101, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cou[abs(a)];
	}
	
	int res = (cou[0] > 0);
	for (int v = 1; v <= 100; ++v) res += min(cou[v], 2);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}