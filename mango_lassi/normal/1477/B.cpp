#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Segment tree for range addition, setting, sum, minimum and maximum
class SegTree {
	private:
		const array<ll, 3> NEUT = {0, 4*(ll)1e18, -4*(ll)1e18};
		struct Row {
			array<ll, 3> dat = {0, 0, 0}; // initial values
			ll tag = 0;
			int tag_t = -1;

			void apply(int t, ll v, int len) {
				if (t == 0) {
					dat[0] += v * len;
					dat[1] += v;
					dat[2] += v;

					if (tag_t == -1) tag_t = 0;
					tag += v;
				} else {
					dat[0] = v * len;
					dat[1] = v;
					dat[2] = v;

					tag_t = 1;
					tag = v;
				}
			}
			static ll combine(int t, ll a, ll b) {
				if (t == 0) return a + b;
				else if (t == 1) return min(a, b);
				else return max(a, b);
			}
		};

		// #################
		// # DO NOT CHANGE #
		// #################

		vector<Row> seg;
		int h = 1;

		// Returns length of interval corresponding to position i
		int len(int i) { return h >> (31 - __builtin_clz(i)); }

		void push(int i) {
			int t = seg[i].tag_t;
			if (t != -1) {
				int ln = len(i) >> 1;
				seg[2*i].apply(t, seg[i].tag, ln);
				seg[2*i+1].apply(t, seg[i].tag, ln);
				seg[i].tag_t = -1;
				seg[i].tag = 0;
			}
		}
		void update(int i) {
			for (int t = 0; t < NEUT.size(); ++t) {
				seg[i].dat[t] = Row::combine(t, seg[2*i].dat[t], seg[2*i+1].dat[t]);
			}
		}

		ll recGet(int t, int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT[t];
			if (a <= ia && ib <= b) return seg[i].dat[t];
			push(i);
			int im = (ia + ib) >> 1;
			return Row::combine(t,
				recGet(t, a, b, 2*i, ia, im),
				recGet(t, a, b, 2*i+1, im, ib));
		}
		void recApply(int t, int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) seg[i].apply(t, v, len(i));
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(t, a, b, v, 2*i, ia, im);
				recApply(t, a, b, v, 2*i+1, im, ib);
				update(i);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h);
		}
		ll rangeSum(int a, int b) { return recGet(0, a, b+1, 1, 0, h); }
		ll rangeMin(int a, int b) { return recGet(1, a, b+1, 1, 0, h); }
		ll rangeMax(int a, int b) { return recGet(2, a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(0, a, b+1, v, 1, 0, h); }
		void rangeSet(int a, int b, ll v) { recApply(1, a, b+1, v, 1, 0, h); }
};

void solve() {
	int n, q;
	cin >> n >> q;

	string str, tar;
	cin >> str >> tar;

	vector<pair<int, int>> qs(q);
	for (auto& pr : qs) {
		cin >> pr.first >> pr.second;
		--pr.first; --pr.second;
	}
	
	SegTree seg(n);
	for (int i = 0; i < n; ++i) seg.rangeAdd(i, i, tar[i] - '0');
	
	for (int qi = q-1; qi >= 0; --qi) {
		int a = qs[qi].first;
		int b = qs[qi].second;
		int len = b-a+1;
		int c = seg.rangeSum(a, b);
		
		if (2*c == len) {
			cout << "NO\n";
			return;
		} else if (2*c > len) {
			seg.rangeSet(a, b, 1);
		} else {
			seg.rangeSet(a, b, 0);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (str[i] - '0' != seg.rangeSum(i, i)) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}