#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
	int n;
	cin >> n;

	vector<int> perm(n);
	for (int& p : perm) cin >> p;

	pair<int, int> max_len = {0, 0};
	vector<int> inc(n, 0), dec(n, 0);

	inc[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (perm[i-1] < perm[i]) inc[i] = inc[i-1] + 1;
		else inc[i] = 1;

		if (inc[i] > max_len.first) {
			max_len = {inc[i], 1};
		} else if (inc[i] == max_len.first) {
			++max_len.second;
		}
	}

	dec[n-1] = 1;
	for (int i = n-2; i >= 0; --i) {
		if (perm[i+1] < perm[i]) dec[i] = dec[i+1] + 1;
		else dec[i] = 1;
		
		if (dec[i] > max_len.first) {
			max_len = {dec[i], 1};
		} else if (dec[i] == max_len.first) {
			++max_len.second;
		}
	}

	// x selects something where p_{i-1} < p_{i} < p_{i+1} -> loss
	int h = max_len.first;
	int c = max_len.second;
	int res = 0;
	for (int x = 0; x < n; ++x) {
		if (inc[x] == h && dec[x] == h && c == 2 && (h % 2) == 1) ++res;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}