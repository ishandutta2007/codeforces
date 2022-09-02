#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 500;
string row[N];
int row_cou[N];
int col_cou[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	int max_row = 0;
	int max_col = 0;
	int first_row = h-1;
	int last_row = 0;
	int first_col = w-1;
	int last_col = 0;
	for (int y = 0; y < h; ++y) {
		cin >> row[y];
		for (int x = 0; x < w; ++x) {
			if (row[y][x] == '*') {
				++row_cou[y];
				++col_cou[x];
				if (row_cou[y] > row_cou[max_row]) max_row = y;
				if (col_cou[x] > col_cou[max_col]) max_col = x;
				first_row = min(first_row, y);
				last_row = max(last_row, y);
				first_col = min(first_col, x);
				last_col = max(last_col, x);
			}
		}
	}

	bool fail = false;
	if (first_row >= max_row || last_row <= max_row) fail = true;
	if (first_col >= max_col || last_col <= max_col) fail = true;

	for (int x = 0; x < w; ++x) {
		if (x == max_col) {
			if (col_cou[x] <= 1) fail = true;
		} else if (first_col <= x && x <= last_col) {
			if (col_cou[x] != 1) fail = true;
		} else {
			if (col_cou[x] != 0) fail = true;
		}
	}
	for (int y = 0; y < h; ++y) {
		if (y == max_row) {
			if (row_cou[y] <= 1) fail = true;
		} else if (first_row <= y && y <= last_row) {
			if (row_cou[y] != 1) fail = true;
		} else {
			if (row_cou[y] != 0) fail = true;
		}
	}
	for (int x = first_col; x <= last_col; ++x) {
		if (row[max_row][x] != '*') fail = true;
	}
	for (int y = first_row; y <= last_row; ++y) {
		if (row[y][max_col] != '*') fail = true;
	}

	if (fail) cout << "NO\n";
	else cout << "YES\n";
}