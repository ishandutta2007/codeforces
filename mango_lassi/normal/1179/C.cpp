#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct SegTree {
	vector<ll> seg;
	vector<ll> add;
	int h = 1;
	
	SegTree(int n) {
		while(h < n) h <<= 1;
		seg.resize(2*h, 0);
		add.resize(2*h, 0);
	}
	void push(int i) {
		if (add[i] == 0) return;
		seg[i] += add[i];
		if (i < h) {
			add[2*i] += add[i];
			add[2*i+1] += add[i];
		}
		add[i] = 0;
	}
	void update(int i) {
		seg[i] = max(seg[2*i], seg[2*i+1]);
	}
	int recLP(int i, int ia, int ib) {
		push(i);
		if (seg[i] <= 0) return -1;
		if (ia == ib) return ia;
		else {
			int im = (ia + ib) >> 1;
			int res;

			res  = recLP(2*i+1, im+1, ib);
			if (res != -1) return res;
			res = recLP(2*i, ia, im);
			if (res != -1) return res;

			return -1;
		}
	}
	void recAddRange(int a, int b, int v, int i, int ia, int ib) {
		push(i);
		if (ib < a || b < ia) return;
		if (a <= ia && ib <= b) {
			add[i] += v;
			push(i);
		} else {
			int im = (ia + ib) >> 1;
			recAddRange(a, b, v, 2*i, ia, im);
			recAddRange(a, b, v, 2*i+1, im+1, ib);
			update(i);
		}
	}
	int lastPositive() {
		return recLP(1, 0, h-1);
	}
	void addRange(int a, int b, int v) {
		recAddRange(a, b, v, 1, 0, h-1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> as(n);
	vector<int> bs(m);
	for (int i = 0; i < n; ++i) cin >> as[i];
	for (int i = 0; i < m; ++i) cin >> bs[i];

	// Order of pupils doesn't matter, dishes of some suffix will be bought
	// if the number of pupils above each of them is at least the number of dishes above them.
	// Store number of pupils above, and number of dishes above. Look for the first positive value
	// (more dishes than people), and take that. So people are -1, and dishes are 1.

	const int V = 10 + (int)1e6;
	SegTree seg(V);
	for (auto v : as) seg.addRange(0, v, 1);
	for (auto v : bs) seg.addRange(0, v, -1);

	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, x;
			cin >> i >> x;
			--i;

			seg.addRange(0, as[i], -1);
			as[i] = x;
			seg.addRange(0, as[i], 1);
		} else {
			int i, x;
			cin >> i >> x;
			--i;

			seg.addRange(0, bs[i], 1);
			bs[i] = x;
			seg.addRange(0, bs[i], -1);
		}
		int res = seg.lastPositive();
		cout << res << '\n';
	}
}