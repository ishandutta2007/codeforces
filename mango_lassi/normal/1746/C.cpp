#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		res[v - 1] = (i + 1) % n;
	}
	for (int i : res) cout << i + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}