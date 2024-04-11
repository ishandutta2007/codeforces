#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<int> perm(n);
	int a = 0, b = n-1;
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			perm[b] = i;
			--b;
		} else {
			perm[a] = i;
			++a;
		}
	}

	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		int b;
		cin >> b;
		res[perm[i]] = b;
	}
	for (auto v : res) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}