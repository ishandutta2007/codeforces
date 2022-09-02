#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ITV {
	array<int, 2> cou;
	int le, ri, prs;

	ITV() {
		cou[0] = 0;
		cou[1] = 0;
		le = -1; ri = -1; prs = 0;
	}

	ITV(char c) {
		int v = c - '0';
		cou[v] = 1;
		cou[v ^ 1] = 0;
		le = v;
		ri = v;
		prs = 0;
	}

	int getCost() const {
		int res = 0;
		for (int v = 0; v <= 1; ++v) {
			int c0 = cou[0] + (v == 0 ? ((le != 0) + (ri != 0)) : 0);
			int c1 = cou[1] + (v == 1 ? ((le != 1) + (ri != 1)) : 0);
			res = max(res, (prs + abs(c0 - c1) + 1) / 2);
		}
		return res;
	}
};

ITV combine(const ITV& le, const ITV& ri) {
	if (le.cou[0] + le.cou[1] == 0) return ri;
	if (ri.cou[0] + ri.cou[1] == 0) return le;

	ITV res;
	res.cou[0] = le.cou[0] + ri.cou[0];
	res.cou[1] = le.cou[1] + ri.cou[1];
	res.le = le.le;
	res.ri = ri.ri;
	res.prs = le.prs + ri.prs + (le.ri == ri.le);
	return res;
}

class SegTree {
	private:
		vector<ITV> seg;
		int h = 1;

		ITV recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return ITV();
			if (a <= ia && ib <= b) return seg[i];
			int im = (ia + ib) >> 1;
			return combine(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
	public:
		SegTree(string str) {
			int n = str.size();
			while(h < n) h *= 2;
			seg.resize(2*h);
			for (int i = h; i < n + h; ++i) seg[i] = ITV(str[i - h]);
			for (int i = h - 1; i > 0; --i) seg[i] = combine(seg[2*i], seg[2*i+1]);
		}
		ITV get(int a, int b) { return recGet(a, b + 1, 1, 0, h); }
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	// One query: remove alternating substring
	// 	always optimal to pick maximal substring

	// Cost to clear, assuming first and last character are the strictly most common character:
	//	1/2 * ((# of adjacent equal pairs) + abs(# ones - # zeros) + 1)

	string str;
	cin >> str;

	SegTree seg(str);

	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		ITV itv = seg.get(a, b);
		cout << itv.getCost() << '\n';
	}
}