#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct Entry {
	ll sum, len, left_sum, right_sum, tot_sum;
};

struct SegTree {
	vector<Entry> ent;
	int h = 1;

	Entry joinEntry(const Entry& le, const Entry& ri) {
		Entry res;
		res.sum = (le.sum + ri.sum) % MOD;
		res.len = le.len + ri.len;
		res.left_sum = (le.left_sum + ri.left_sum + le.sum * ri.len) % MOD;
		res.right_sum = (ri.right_sum + le.right_sum + ri.sum * le.len) % MOD;
		res.tot_sum = (le.tot_sum + ri.tot_sum + le.right_sum * ri.len + ri.left_sum * le.len) % MOD;
		return res;
	}

	SegTree(int n) {
		while(h < n) h <<= 1;
		ent.resize(2*h);
		for (int i = h; i < h+n; ++i) {
			ent[i] = {1,1,1,1,1};
		}
		for (int i = h+n; i < 2*h; ++i) {
			ent[i] = {0,0,0,0,0};
		}
		for (int i = h-1; i >= 1; --i) {
			ent[i] = joinEntry(ent[2*i], ent[2*i+1]);
		}
	}

	void set(int i, int v) {
		i += h;
		ent[i].sum = v;
		ent[i].left_sum = v;
		ent[i].right_sum = v;
		for (i >>= 1; i >= 1; i >>= 1) {
			ent[i] = joinEntry(ent[2*i], ent[2*i+1]);
		}
	}
	Entry recGet(int a, int b, int i, int ia, int ib) {
		if (a <= ia && ib <= b) return ent[i];
		if (b < ia || ib < a) return {0,0,0,0};
		int mid = (ia + ib) >> 1;
		Entry le = recGet(a, b, 2*i, ia, mid);
		Entry ri = recGet(a, b, 2*i+1, mid+1, ib);
		return joinEntry(le, ri);
	}
	ll get(int a, int b) {
		if (b < a) return 0;
		else return recGet(a, b, 1, 0, h-1).tot_sum;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i].first;
		vals[i].second = i;
	}
	sort(vals.begin(), vals.end());

	SegTree seg(n);

	ll res = 0;
	for (int j = n-1; j >= 0; --j) {
		ll v = vals[j].first;
		int i = vals[j].second;
		ll mult = (seg.get(0, n-1) - seg.get(0, i-1) - seg.get(i+1, n-1)) % MOD;
		// cout << i << ' ' << v << ' ' << mult << '\n';
		res += (mult * v) % MOD;

		seg.set(i, 0); // Disable value
	}

	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}