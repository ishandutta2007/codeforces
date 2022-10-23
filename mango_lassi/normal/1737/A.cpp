#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int C = 26;

void solve() {
	int n, k;
	cin >> n >> k;
	int h = min(C, n/k);
	string str;
	cin >> str;

	vector<int> cou(C, 0);
	for (auto c : str) ++cou[c - 'a'];
	for (int i = 1; i < C; ++i) cou[i] = min(cou[i], cou[i - 1]);
	for (int i = h; i < C; ++i) cou[i] = 0;

	string res(k, '?');
	for (int i = 0, j = k-1; i < C; ++i) {
		while(j >= cou[i]) {
			res[j] = ('a' + i);
			--j;
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}