#include <iostream>
#include <utility>
using namespace std;

const int N = 1<<17;
int h = 1;

// First: amount of B's
// Second: Amount of A's on right side
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
	int fi = a.first + b.first;
	int ri = (b.first == 0 ? a.second + b.second : b.second);
	return {fi, ri};
}

pair<int, int> vals[2][2*N];

pair<int, int> get(int a, int b, int j, int ia = 0, int ib = h-1, int i = 1) {
	if (b < ia || ib < a) return {0, 0};
	if (a <= ia&&ib <= b) return vals[j][i];
	int mid = (ia + ib) >> 1;
	return combine(get(a, b, j, ia, mid, 2*i), get(a, b, j, mid+1, ib, 2*i+1));
}

int main() {
	string str;
	string tar;
	cin >> str >> tar;
	int n = str.size();
	int m = tar.size();
	while(h < n || h < m) h <<= 1;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'A') {
			vals[0][i+h] = {0, 1};
		} else {
			vals[0][i+h] = {1, 0};
		}
	}
	for (int i = 0; i < m; ++i) {
		if (tar[i] == 'A') {
			vals[1][i+h] = {0, 1};
		} else {
			vals[1][i+h] = {1, 0};
		}
	}
	for (int i = h-1; i > 0; --i) {
		vals[0][i] = combine(vals[0][2*i], vals[0][2*i+1]);
		vals[1][i] = combine(vals[1][2*i], vals[1][2*i+1]);
	}
	
	int q;
	cin >> q;
	while(q--) {
		int as, ae, bs, be;
		cin >> as >> ae >> bs >> be;
		--as; --ae; --bs; --be;
		pair<int, int> str_vals = get(as, ae, 0);
		pair<int, int> tar_vals = get(bs, be, 1);
		//cout << as << ' ' << ae << ' ' << bs << ' ' << be << '\n';
		//cout << str_vals.first << ' ' << str_vals.second << ' ' << tar_vals.first << ' ' << tar_vals.second << '\n';
		bool can = true;
		if (str_vals.first == 0 && tar_vals.first > 0) {
			if (str_vals.second == 0) {
				can = false;
			} else {
				str_vals = {2, min(str_vals.second-1, tar_vals.second)};
			}
		}
		// b's must have same parity
		if ((str_vals.first & 1) != (tar_vals.first & 1)) {
			can = false;
		}
		// amount of b's can't decrease
		if (tar_vals.first < str_vals.first) {
			can = false;
		}
		// amount of a's can't increase
		if (str_vals.second < tar_vals.second) {
			can = false;
		}
		// a's mod 3 can only change if b's are increased by 2
		if (((str_vals.second % 3) != (tar_vals.second % 3)) && (str_vals.first == tar_vals.first)) {
			can = false;
		}
		cout << can;
	}
	cout << '\n';
}