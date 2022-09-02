#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) {
		cin >> a;
		--a;
	}

	vector<vector<int>> apps(n);
	for (int i = 0; i < n; ++i) apps[i].push_back(n);

	for (int i = n-1; i >= 0; --i) {
		apps[as[i]].push_back(i);
	}

	int res = n;
	int x0 = -1, x1 = -1;
	for (int i = 0; i < n; ++i) {
		if (x0 == as[i] || x1 == as[i]) {
			--res;
		} else if (x0 == -1) {
			x0 = as[i];
		} else if (x1 == -1) {
			x1 = as[i];
		} else {
			while(apps[x0].back() <= i) apps[x0].pop_back();
			while(apps[x1].back() <= i) apps[x1].pop_back();
			if (apps[x0].back() > apps[x1].back()) {
				x0 = as[i];
			} else {
				x1 = as[i];
			}
		}
	}
	cout << res << '\n';
}