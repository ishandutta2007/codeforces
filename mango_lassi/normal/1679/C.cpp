#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> rowc(n, 0), colc(n, 0);
	set<int> empty_rows, empty_cols;
	for (int i = 0; i <= n; ++i) {
		empty_rows.insert(i);
		empty_cols.insert(i);
	}

	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int y, x;
			cin >> y >> x;
			--y; --x;

			++rowc[y];
			++colc[x];
			if (rowc[y] == 1) empty_rows.erase(y);
			if (colc[x] == 1) empty_cols.erase(x);
		} else if (t == 2) {
			int y, x;
			cin >> y >> x;
			--y; --x;

			--rowc[y];
			--colc[x];
			if (rowc[y] == 0) empty_rows.insert(y);
			if (colc[x] == 0) empty_cols.insert(x);
		} else {
			int y0, x0, y1, x1;
			cin >> y0 >> x0 >> y1 >> x1;
			--y0; --x0; --y1; --x1;

			/*
			cerr << y0 << ' ' << x0 << ' ' << y1 << ' ' << x1 << '\n';
			for (int y : empty_rows) cerr << y << ' '; cerr << '\n';
			for (int x : empty_cols) cerr << x << ' '; cerr << '\n';
			cerr << (*(empty_rows.lower_bound(y0))) << ' ' << (*(empty_cols.lower_bound(x0))) << '\n';
			*/

			bool ans = 0;
			ans |= (*(empty_rows.lower_bound(y0))) > y1;
			ans |= (*(empty_cols.lower_bound(x0))) > x1;
			if (ans) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}