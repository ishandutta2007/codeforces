#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4 * (ll)1e18;

class SegTree {
	private:
		vector<ll> seg, sum, wsum, cou, weight, tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] += v;
			sum[i] += cou[i] * v;
			wsum[i] += weight[i] * v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}

		pair<ll, ll> recGetSums(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return {0ll, 0ll};
			if (a <= ia && ib <= b) return {sum[i], wsum[i]};
			push(i);
			int im = (ia + ib) >> 1;
			auto le = recGetSums(a, b, 2*i, ia, im);
			auto ri = recGetSums(a, b, 2*i+1, im, ib);
			return {le.first + ri.first, le.second + ri.second};
		}
		void recAdd(int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recAdd(a, b, v, 2*i, ia, im);
				recAdd(a, b, v, 2*i+1, im, ib);

				seg[i] = min(seg[2*i], seg[2*i+1]);
				sum[i] = sum[2*i] + sum[2*i+1];
				wsum[i] = wsum[2*i] + wsum[2*i+1];
			}
		}
		int recFind(int a, int b, ll v, int i, int ia, int ib) {
			if (seg[i] > v) return b;
			if (b <= ia || ib <= a) return b;
			if (ib == ia + 1) return ia;

			push(i);
			int im = (ia + ib) >> 1;
			int off = recFind(a, b, v, 2*i, ia, im);
			if (off < b) return off;
			else return recFind(a, b, v, 2*i+1, im, ib);
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, 0);
			sum.resize(2*h, 0);
			wsum.resize(2*h, 0);
			cou.resize(2*h, 0);
			weight.resize(2*h, 0);
			tag.resize(h, 0);

			for (int i = 0; i < n; ++i) {
				weight[i + h] = i;
				cou[i + h] = 1;
			}
			for (int i = h - 1; i > 0; --i) {
				weight[i] = weight[2*i] + weight[2*i+1];
				cou[i] = cou[2*i] + cou[2*i+1];
			}
		}
		
		// \sum_{i = a}^{b} val[i] * (base + inc * (i-a))
		ll rangeMulSum(int a, int b, ll base, ll inc) {
			if (b < a) return 0;
			auto pr = recGetSums(a, b + 1, 1, 0, h);
			return base * pr.first + (pr.second - a * pr.first) * inc;
		}
		void rangeAdd(int a, int b, ll v) { recAdd(a, b+1, v, 1, 0, h); }
		
		// Min index i, s.t. a <= i <= b and val[i] <= v. Returns b + 1 if none is found
		int findNext(int a, int b, ll v) { return recFind(a, b+1, v, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<ll> da(n + 1, 0);
	for (int i = 1; i <= n; ++i) cin >> da[i];
	for (int i = n; i > 0; --i) da[i] -= da[i-1];

	vector<ll> bs(m + 1, 0);
	for (int i = 1; i <= m; ++i) cin >> bs[i];
	SegTree seg(m);
	for (int i = 0; i < m; ++i) seg.rangeAdd(i, i, -(bs[i + 1] - bs[i]));

	for (int qi = 0; qi < q; ++qi) {
		int t, k;
		ll d;
		cin >> t >> k >> d;
		if (t == 1) {
			for (int i = n-k+1; i <= n; ++i) da[i] += d;
		} else {
			seg.rangeAdd(m-k, m-1, -d);
		}

		ll res = (n + m - 1) * (da[1] - seg.rangeMulSum(0, 0, 1, 0));

		int j = 1, i = 1;
		for (; i < n; ++i) {
			int j2 = seg.findNext(j, m-1, -da[i + 1]);
			res += -seg.rangeMulSum(j, j2 - 1, (n - i) + (m - j), -1);
			j = j2;
			res += da[i + 1] * ((n - i) + (m - j));
		}
	
		ll tmp = -seg.rangeMulSum(j, m-1, (n - i) + (m - j), -1);
		res += tmp;
		cout << res << '\n';
	}
}