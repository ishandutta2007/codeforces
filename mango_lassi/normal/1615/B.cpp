#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2 * (int)1e5;
const int H = 20;
int cou[N + 1][H];

void solve() {
	int a, b;
	cin >> a >> b;

	int len = b - a + 1;
	int res = len;
	for (int j = 0; j < H; ++j) {
		int c = cou[b][j] - cou[a-1][j];
		res = min(res, len - c);
	}
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int j = 0; j < H; ++j) {
		for (int i = 1; i <= N; ++i) {
			cou[i][j] = cou[i-1][j] + (bool)(i & (1 << j));
		}
	}

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}