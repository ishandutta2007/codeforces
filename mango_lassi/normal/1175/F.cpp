#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;
using ll = long long;

struct SegTree {
	const int INF = 1e9;
	vector<pair<int, int>> max_vc;
	vector<int> add;
	int h = 1;

	pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return {a.first, a.second + b.second};
		else return max(a, b);
	}
	void push(int i) {
		max_vc[i].first += add[i];
		if (i < h) {
			add[2*i] += add[i];
			add[2*i+1] += add[i];
		}
		add[i] = 0;
	}

	SegTree(int n, int v) {
		while(h < n) h <<= 1;
		max_vc.resize(2*h, {v, 1});
		add.resize(2*h, 0);
		for (int i = h-1; i > 0; --i) max_vc[i] = combine(max_vc[2*i], max_vc[2*i+1]);
	}

	void recAdd(int a, int b, int v, int i, int ia, int ib) {
		push(i);
		if (ib < a || b < ia) return;
		if (a <= ia && ib <= b) {
			add[i] += v;
			push(i);
		} else {
			int im = (ia + ib) >> 1;
			recAdd(a, b, v, 2*i, ia, im);
			recAdd(a, b, v, 2*i+1, im+1, ib);
			max_vc[i] = combine(max_vc[2*i], max_vc[2*i+1]);
		}
	}

	pair<int, int> recGet(int a, int b, int i, int ia, int ib) {
		push(i);
		if (ib < a || b < ia) return {-INF, 0};
		if (a <= ia && ib <= b) return max_vc[i];
		int im = (ia + ib) >> 1;
		return combine(recGet(a, b, 2*i, ia, im), recGet(a, b, 2*i+1, im+1, ib));
	}

	void addInt(int a, int b, int v) {
		recAdd(a, b, v, 1, 0, h-1);
	}
	pair<int, int> getInt(int a, int b) {
		return recGet(a, b, 1, 0, h-1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Must have max == len == active
	// active <= max, len
	// 2*active - max - len <= 0

	// Move end of current interval. Keep only last occurence of value alive
	// Store in each position active_[i,a] - max(x_[i, a])
	// These values are always <= 0 since only unique values are active. So we can just count the number of
	// zeroes in the range to find answer.

	int n;
	cin >> n;
	SegTree seg(n, 0);
	vector<pair<int, int>> maxes;
	map<int, int> prevs; // Previous occurrences of numbers

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		if (prevs.find(a) != prevs.end()) {
			int p = prevs[a];
			seg.addInt(p+1, i, 2);
		} else {
			seg.addInt(0, i, 2);
		}
		seg.addInt(0, i, -1); // Len

		prevs[a] = i;

		seg.addInt(i, i, -a);
		pair<int, int> maxes_add = {a, i};
		while((! maxes.empty()) && (maxes.back().first <= a)) {
			seg.addInt(maxes.back().second, maxes_add.second - 1, -(a - maxes.back().first));
			maxes_add.second = maxes.back().second;
			maxes.pop_back();
		}
		maxes.push_back(maxes_add);

		pair<int, int> sub = seg.getInt(0, i);
		if (sub.first == 0) res += sub.second;
	}
	cout << res << '\n';
}