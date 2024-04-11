#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	pair<int,int> opt = {n + 1, n};
	for (int i = 1; i <= n; ++i) {
		int j = (n + i - 1) / i;
		opt = min(opt, {i + j, i});
	}
	// cout << opt.first << '\n';
	int cur = 1;
	while (cur <= n) {
		int l = cur, r = min(n, cur + opt.second - 1);
		for (int i = r; i >= l; --i) cout << i << ' ';
		cur = r + 1;
	}
}