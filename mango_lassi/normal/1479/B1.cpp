#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<int> nxt(n, -1);
	for (int i = n-2; i >= 0; --i) {
		if (as[i] == as[i+1]) nxt[i] = as[i];
		else nxt[i] = nxt[i+1];
	}

	int res = 0;
	int x0 = -1, x1 = -1;
	for (int i = 0; i < n; ++i) {
		if (x0 == as[i] && x1 == as[i]) continue;
		if (x0 == as[i] || (x1 != as[i] && x0 != nxt[i])) {
			++res;
			x1 = as[i];
		} else {
			++res;
			x0 = as[i];
		}
	}
	cout << res << '\n';
}