#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
int yx[N];
int xy[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		yx[i] = -1;
		xy[i] = -1;
	}
	for (int i = 0; i < m; ++i) {
		int y, x;
		cin >> y >> x;
		--y; --x;
		yx[x] = y;
		xy[y] = x;
	}

	int res = 0;

	// 1. Deal with paths
	for (int i = 0; i < n; ++i) {
		if (yx[i] == i) {
			yx[i] = -1;
			xy[i] = -1;
		}
		if (yx[i] == -1 && xy[i] == -1) continue;
		if (yx[i] == -1) {
			int j = i;
			while(xy[j] != -1) {
				int nxt = xy[j];
				xy[j] = -1;
				yx[j] = -1;
				j = nxt;
				++res;
			}
			yx[j] = -1;
		}
	}
	// 2. Deal with cycles
	for (int i = 0; i < n; ++i) {
		if (yx[i] == -1 || xy[i] == -1) continue;
		++res;

		int j = i;
		do {
			++res;
			int nxt = yx[j];
			yx[j] = -1;
			xy[j] = -1;
			j = nxt;
		} while (j != i);
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