#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> ban(n, 0);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		ban[b-1] = 1;
	}

	int r = -1;
	for (int i = 0; i < n; ++i) {
		if (ban[i] == 0) r = i;
	}
	
	for (int i = 0; i < n; ++i) {
		if (i != r) {
			cout << r + 1 << ' ' << i + 1 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}