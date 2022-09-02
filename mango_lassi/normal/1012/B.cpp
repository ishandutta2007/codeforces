#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 2*(int)1e5;
int row_comp[N];
int col_comp[N];

int collapse(int i, int* gr) {
	if (gr[i] != i) gr[i] = collapse(gr[i], gr);
	return gr[i];
}
int join(int a, int b, int* gr) {
	a = collapse(a, gr);
	b = collapse(b, gr);
	if (a == b) return 0;
	gr[b] = a;
	return 1;
}

vector<int> row_els[N];
vector<int> col_els[N];

int main() {
	// You need to make both all rows and columns connected.
	// Two rows are connected if they both have a element at the same x-coordinate.
	// Similarly for columns.

	// 1 0 0 0 
	// 1 1 0 0
	// 1 0 1 0
	// 1 0 0 1
	// 1 0 0 0

	// 1 0 0 0
	// 0 1 0 0
	// 0 1 1 0
	// 1 1 0 1

	int w, h, n;
	cin >> w >> h >> n;

	if (w == 1 || h == 1) {
		cout << (w+h-n-1) << '\n';
	} else {
		for (int i = 0; i < w; ++i) col_comp[i] = i;
		for (int i = 0; i < h; ++i) row_comp[i] = i;

		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			row_els[y].push_back(x);
			col_els[x].push_back(y);
		}
		int x_empt = 0;
		int y_empt = 0;
		int x_comps = w;
		int y_comps = h;
		for (int x = 0; x < w; ++x) {
			if (col_els[x].empty()) ++x_empt;
			for (int i = 1; i < col_els[x].size(); ++i) {
				y_comps -= join(col_els[x][0], col_els[x][i], col_comp);
			}
		}
		for (int y = 0; y < h; ++y) {
			if (row_els[y].empty()) ++y_empt;
			for (int i = 1; i < row_els[y].size(); ++i) {
				x_comps -= join(row_els[y][0], row_els[y][i], row_comp);
			}
		}

		// cout << x_empt << ' ' << y_empt << ' ' << x_comps << ' ' << y_comps << '\n';
		cout << min(x_comps-1 + y_empt, y_comps-1 + x_empt) << '\n';
	}
}