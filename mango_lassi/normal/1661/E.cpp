#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Ele {
	int cou = 0;
	array<int, 3> le, ri;

	Ele() {
		for (int j = 0; j < 3; ++j) {
			le[j] = -1;
			ri[j] = -1;
		}
	}
	Ele(const array<char, 3>& chs) {
		for (int j = 0; j < 3; ++j) {
			le[j] = -1; ri[j] = -1;
		}
		if (chs[1] == '1') {
			le[1] = 0; ri[1] = 0;
			for (int j = 0; j < 3; j += 2) {
				if (chs[j] == '1') {
					le[j] = 0; ri[j] = 0;
				}
			}
			cou = 1;
		} else {
			for (int j = 0; j < 3; j += 2) {
				if (chs[j] == '1') {
					le[j] = cou; ri[j] = cou;
					++cou;
				}
			}
		}
	}
	Ele(const Ele& a, const Ele& b) {
		cou = a.cou + b.cou;
		array<int, 8> comp, apps;
		for (int i = 0; i < 8; ++i) {
			comp[i] = i;
			apps[i] = 0;
		}
		for (int j = 0; j < 3; ++j) {
			if (a.ri[j] != -1 && b.le[j] != -1) {
				int x = a.ri[j], y = b.le[j] + 4;
				while(comp[x] != x) x = comp[x];
				while(comp[y] != y) y = comp[y];
				cou -= (x != y);
				comp[y] = x;
			}
		}
		for (int j = 0; j < 3; ++j) {
			le[j] = a.le[j];
			ri[j] = (b.ri[j] == -1 ? -1 : b.ri[j] + 4);
			while(le[j] != -1 && comp[le[j]] != le[j]) le[j] = comp[le[j]];
			while(ri[j] != -1 && comp[ri[j]] != ri[j]) ri[j] = comp[ri[j]];
			if (le[j] != -1) apps[le[j]] = 1;
			if (ri[j] != -1) apps[ri[j]] = 1;
		}
		for (int i = 1; i < 8; ++i) apps[i] += apps[i-1];
		for (int j = 0; j < 3; ++j) {
			if (le[j] != -1) le[j] = apps[le[j]] - 1;
			if (ri[j] != -1) ri[j] = apps[ri[j]] - 1;
		}
	}
};

class SegTree {
	private:
		vector<Ele> seg;
		int h = 1;

		Ele recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return Ele();
			if (a <= ia && ib <= b) return seg[i];
			int im = (ia + ib) >> 1;
			return Ele(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
	public:
		SegTree(const array<string, 3>& arr) {
			int n = arr[0].size();
			while(h < n) h *= 2;

			seg.resize(2*h, Ele());
			for (int i = 0; i < n; ++i) {
				array<char, 3> col;
				for (int j = 0; j < 3; ++j) col[j] = arr[j][i];
				seg[i + h] = Ele(col);
			}
			for (int i = h-1; i > 0; --i) seg[i] = Ele(seg[2*i], seg[2*i+1]);
		}
		Ele get(int a, int b) { return recGet(a, b + 1, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	array<string, 3> arr;
	for (int y = 0; y < 3; ++y) cin >> arr[y];
	SegTree seg(arr);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		Ele el = seg.get(a-1, b-1);
		cout << el.cou << '\n';
	}
}