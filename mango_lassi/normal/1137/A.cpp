#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

const int N = 1000 + 10;
int val[N][N];
int rows[N][N];
int cols[N][N];
int row_vals[N];
int col_vals[N];

int norm(int v) {
	if (v < 0) return -1;
	if (v > 0) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> val[x][y];
		}
	}
	for (int x = 0; x < w; ++x) {
		vector<pair<int, int>> col(h);
		for (int y = 0; y < h; ++y) col[y] = {val[x][y], y};
		sort(col.begin(), col.end());

		int cou = 0;
		cols[x][col[0].second] = cou;
		for (int i = 1; i < h; ++i) {
			if (col[i].first != col[i-1].first) ++cou;
			cols[x][col[i].second] = cou;
		}
		col_vals[x] = cou;
	}
	for (int y = 0; y < h; ++y) {
		vector<pair<int, int>> row(w);
		for (int x = 0; x < w; ++x) row[x] = {val[x][y], x};
		sort(row.begin(), row.end());

		int cou = 0;
		rows[row[0].second][y] = cou;
		for (int i = 1; i < w; ++i) {
			if (row[i].first != row[i-1].first) ++cou;
			rows[row[i].second][y] = cou;
		}
		row_vals[y] = cou;
	}

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int v1 = rows[x][y];
			int v2 = cols[x][y];

			int v = max(v1 + 1, v2 + 1);
			int res = max(row_vals[y] + (v - v1), col_vals[x] + (v - v2));
			cout << res << ' ';
		}
		cout << '\n';
	}
}