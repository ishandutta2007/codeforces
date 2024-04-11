#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using itv = array<array<int, 3>, 3>;
const int INF = (int)1e9 + 7;

// Segment tree for range addition and range sum. It is also easy to modify:
// just change NEUT, apply, and combine to what you need, and rename rangeSum, rangeAdd
class SegTree {
	private:
		// Min number of ops so that entering with i matches, we exit with j matches
		itv neut;
		vector<itv> seg;
		int h = 1;

		itv combine(itv a, itv b) {
			itv res;
			for (int i = 0; i < 3; ++i) {
				for (int j = i; j < 3; ++j) {
					res[i][j] = INF;
					for (int x = i; x <= j; ++x) {
						res[i][j] = min(res[i][j], a[i][x] + b[x][j]);
					}
				}
			}
			return res;
		}
	public:
		void setChar(int i, char c) {
			itv base = neut;
			if (c == 'a') base[0][0] = 1;
			else if (c == 'b') base[1][1] = 1;
			else if (c == 'c') base[2][2] = 1;
			seg[i + h] = base;
			for (i = (i + h) >> 1; i > 0; i >>= 1) seg[i] = combine(seg[2*i], seg[2*i+1]);
		}
		int getAns() { return seg[1][0][2]; }

		SegTree(string str) {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) neut[i][j] = INF * (i > j);
			}

			while(h < str.size()) h *= 2;
			seg.resize(2*h, neut);

			for (int i = 0; i < str.size(); ++i) setChar(i, str[i]);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	string str;
	cin >> str;
	SegTree seg(str);

	for (int qi = 0; qi < q; ++qi) {
		int i;
		char c;
		cin >> i >> c;
		--i;

		seg.setChar(i, c);
		cout << seg.getAns() << '\n';
	}
}