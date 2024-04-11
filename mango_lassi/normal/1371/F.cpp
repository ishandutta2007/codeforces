#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;
using Data = array<array<int, 5>, 2>;

Data ept;

// data[0][0]: longest >><<
// data[0][1]: longest left <<
// data[0][2]: longest right >>
// data[0][3]: longest left >><<
// data[0][4]: longest right >><<
// data[1][?]: same inverted

// "find length of longest sequence >>>><<<<"
// Maintain longest >><< inside block, longest << at its start, longest <<>> at its start, and same for reverse, and other end.

void updateHalf(array<int, 5>& arr, const array<int, 5>& le, const array<int, 5>& ri, int len1, int len2) {
	// longest left <<
	if (len1 == le[1]) {
		arr[1] = len1 + ri[1];
	} else {
		arr[1] = le[1];
	}

	// longest right >>
	if (len2 == ri[2]) {
		arr[2] = len2 + le[2];
	} else {
		arr[2] = ri[2];
	}

	// longest left >><<
	if (len1 == le[2]) {
		arr[3] = len1 + ri[3];
	} else if (len1 == le[3]) {
		arr[3] = len1 + ri[1];
	} else {
		arr[3] = le[3];
	}

	// longest right >><<
	if (len2 == ri[1]) {
		arr[4] = len2 + le[4];
	} else if (len2 == ri[4]) {
		arr[4] = len2 + le[2];
	} else {
		arr[4] = ri[4];
	}

	// longest >><<
	int off0 = max(le[0], ri[0]);
	int off1 = max(le[4] + ri[1], le[2] + ri[3]);
	arr[0] = max(off0, off1);
}

class SegTree {
	private:
		vector<int> tag;
		vector<Data> data;
		int h = 1;

		// Returns length of interval corresponding to position i
		ll len(int i) { return h >> (31 - __builtin_clz(i)); }

		void apply(int i) {
			swap(data[i][0], data[i][1]);
			if (i < h) tag[i] ^= 1;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i);
			apply(2*i+1);
			tag[i] = 0;
		}
		void update(Data& dt, const Data& le, const Data& ri, int len1, int len2) {
			updateHalf(dt[0], le[0], ri[0], len1, len2);
			updateHalf(dt[1], le[1], ri[1], len1, len2);
		}
		pair<Data, int> recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return make_pair(ept, 0);
			if (a <= ia && ib <= b) return make_pair(data[i], len(i));
			else {
				push(i);
				int im = (ia + ib) >> 1;
				auto le = recGet(a, b, 2*i, ia, im);
				auto ri = recGet(a, b, 2*i+1, im, ib);
				
				Data res = ept;
				update(res, le.first, ri.first, le.second, ri.second);
				return make_pair(res, le.second + ri.second);
			}
		}
		void recApply(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(a, b, 2*i, ia, im);
				recApply(a, b, 2*i+1, im, ib);
				update(data[i], data[2*i], data[2*i+1], len(2*i), len(2*i+1));
			}
		}
	public:
		SegTree(const string& str) {
			int n = str.size();
			while(h < n) h *= 2;
			data.resize(2*h);
			tag.resize(h, 0);
			for (int i = h; i < h+n; ++i) {
				for (int b = 0; b <= 1; ++b) {
					data[i][b][0] = 1;
					data[i][b][1] = b ^ (str[i-h] == '<');
					data[i][b][2] = b ^ (str[i-h] == '>');
					data[i][b][3] = 1;
					data[i][b][4] = 1;
				}
			}
			for (int i = h-1; i >= 1; --i) update(data[i], data[2*i], data[2*i+1], len(2*i), len(2*i+1));

			/*
			for (int i = 1; i < 2*h; ++i) {
				cerr << i << ": ";
				for (int j = 0; j < 5; ++j) {
					cerr << data[i][0][j] << ' ';
				}
				cerr << '\n';
			}
			*/
		}
		int get(int a, int b) {
			return recGet(a, b+1, 1, 0, h).first[0][0];
		}
		void flip(int a, int b) {
			recApply(a, b+1, 1, 0, h);
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
		int a, b;
		cin >> a >> b;
		--a; --b;

		seg.flip(a, b);
		cout << seg.get(a, b) << '\n';
	}
}