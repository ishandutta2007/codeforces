#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int V = 1e9;
const int N = 3 * (int)1e5;
const int M = 8;
int val[N][M];
int can[1<<M];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int all = (1 << m) - 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> val[i][j];
	}

	int low = 0;
	int high = V;
	pair<int, int> res;
	while(low <= high) {
		for (int i = 0; i <= all; ++i) can[i] = -1;

		int mid = (low + high) >> 1;
		for (int i = 0; i < n; ++i) {
			int off = 0;
			for (int j = 0; j < m; ++j) {
				if (val[i][j] >= mid) off |= 1<<j;
			}
			can[off] = i;
		}

		pair<int, int> off = {-1, -1};
		for (int i = all; i >= 0; --i) {
			if (can[i] == -1) continue;

			for (int j = 0; j < m; ++j) {
				if (i & (1<<j)) can[i ^ (1 << j)] = can[i];
			}
			if (can[all ^ i] != -1) {
				off = {can[i], can[all ^ i]};
			}
		}
		if (off.first != -1) {
			low = mid + 1;
			res = off;
		} else high = mid - 1;
	}
	cout << res.first + 1 << ' ' << res.second + 1 << '\n';
}