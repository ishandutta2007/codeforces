#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int h, w;
	cin >> h >> w;
	int n = h * w;

	string str;
	cin >> str;
	vector<int> cou(n + 1, 0);
	for (int i = 1; i <= n; ++i) cou[i] = cou[i - 1] + (str[i - 1] == '1');

	vector<int> res(h*w, 0);
	
	// Handle columns
	int act = 0;
	vector<int> cur(w, 0);
	for (int i = 0; i < h * w; ++i) {
		if (str[i] == '1') {
			act += (cur[i % w] == 0);
			cur[i % w] = 1;
		}
		res[i] += act;
	}

	// Handle rows
	// Handle w updates at once
	for (int r = 0; r < w; ++r) {
		act = 0;
		for (int i = 0; i < h; ++i) {
			act += ((cou[r + i*w + 1] - cou[max(0, r + (i - 1)*w + 1)]) >= 1);
			res[r + i * w] += act;
		}
	}

	for (int i = 0; i < h * w; ++i) cout << res[i] << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}