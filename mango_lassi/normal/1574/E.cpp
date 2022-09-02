#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b & 1) return modPow(a, b ^ 1) * a % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}
ll mAdd(ll a, ll b) {
	if (a + b >= MOD) return a + b - MOD;
	else return a + b;
}
ll mSub(ll a, ll b) {
	if (a >= b) return a - b;
	else return a - b + MOD;
}

const int N = 1e6;
int cou[2][N][4];


pair<bool, bool> getStatus(int j, int y) {
	bool breaks_alt = 0;
	for (int i = 0; i < 4; ++i) {
		if (cou[j][y][i] > 0 && cou[j][y][i ^ 1] > 0) breaks_alt = 1;
		if (cou[j][y][i] > 0 && cou[j][y][i ^ 2] > 0) breaks_alt = 1;
	}
	bool is_empty = (cou[j][y][0] == 0) && (cou[j][y][1] == 0) && (cou[j][y][2] == 0) && (cou[j][y][3] == 0);
	return {is_empty, breaks_alt};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w, k;
	cin >> h >> w >> k;

	// Go column by column
	// If the previous column was either 01010... or 10101..., this column can be and must be one of those two
	// Otherwise, this column is the reverse of the previous column
	// -> Either rows or columns alternate!

	// -> See if rows can alternate and add 2^unset columns
	// -> See if columns can alternate and add 2^unset rows
	// -> See if both can alternate and subtract those

	int row_alt_break = 0, col_alt_break = 0;
	int empty_rows = h, empty_cols = w;
	int tot_even = 0, tot_odd = 0;

	map<pair<int, int>, int> vals;

	for (int i = 0; i < k; ++i) {
		int y, x, t;
		cin >> y >> x >> t;
		--y; --x;

		auto row_stat = getStatus(0, y);
		auto col_stat = getStatus(1, x);

		empty_rows -= row_stat.first;
		row_alt_break -= row_stat.second;
		empty_cols -= col_stat.first;
		col_alt_break -= col_stat.second;
		
		auto it = vals.find(make_pair(y, x));
		if (it != vals.end()) {
			int v = (*it).second;
			vals.erase(it);

			if ((x ^ y ^ v) & 1) --tot_odd;
			else --tot_even;
			--cou[0][y][2*v ^ (x & 1)];
			--cou[1][x][2*v ^ (y & 1)];
		}	

		if (t != -1) {
			int v = t;
			vals[make_pair(y, x)] = v;
			
			if ((x ^ y ^ v) & 1) ++tot_odd;
			else ++tot_even;

			++cou[0][y][2*v ^ (x & 1)];
			++cou[1][x][2*v ^ (y & 1)];
		}

		row_stat = getStatus(0, y);
		col_stat = getStatus(1, x);

		empty_rows += row_stat.first;
		row_alt_break += row_stat.second;
		empty_cols += col_stat.first;
		col_alt_break += col_stat.second;

		ll res = 0;
		if (row_alt_break == 0) res = mAdd(res, modPow(2, empty_rows));
		if (col_alt_break == 0) res = mAdd(res, modPow(2, empty_cols));
		if (tot_even == 0) res = mSub(res, 1);
		if (tot_odd == 0) res = mSub(res, 1);

		// cerr << row_alt_break << ' ' << col_alt_break << ' ' << empty_cols << ' ' << empty_rows << ' ' << tot_even << ' ' << tot_odd << ": ";
		cout << res << '\n';
	}
}