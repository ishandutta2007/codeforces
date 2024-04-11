#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// Segment tree supporting range addition and range sum query
struct SegTree {
	vector<ll> sum;
	vector<ll> add;
	int h = 1;

	SegTree(int n) {
		while(h < n) h <<= 1;
		sum.resize(2*h, 0);
		add.resize(2*h, 0);
	}
	void push(int i, int ia, int ib) {
		if (add[i] == 0) return;
		if (ia != ib) {
			add[2*i] += add[i];
			add[2*i+1] += add[i];
		}
		sum[i] += add[i] * (ib-ia+1);
		add[i] = 0;
	}
	void update(int i) {
		sum[i] = sum[2*i] + sum[2*i+1];
	}

	void recAddRange(int a, int b, ll v, int i, int ia, int ib) {
		push(i, ia, ib);
		if (b < ia || ib < a) return;
		if (a <= ia && ib <= b) {
			add[i] += v;
			push(i, ia, ib);
		} else {
			int im = (ia + ib) >> 1;
			recAddRange(a, b, v, 2*i, ia, im);
			recAddRange(a, b, v, 2*i+1, im+1, ib);
			update(i);
		}
	}
	ll recSumRange(int a, int b, int i, int ia, int ib) {
		push(i, ia, ib);
		if (b < ia || ib < a) return 0;
		if (a <= ia && ib <= b) return sum[i];
		int im = (ia + ib) >> 1;
		ll res = 0;
		res += recSumRange(a, b, 2*i, ia, im);
		res += recSumRange(a, b, 2*i+1, im+1, ib);
		return res;
	}

	void addRange(int a, int b, ll v) {
		recAddRange(a, b, v, 1, 0, h-1);
	}
	ll sumRange(int a, int b) {
		return recSumRange(a, b, 1, 0, h-1);
	}
};

// Given interval, find sum of lengths of greedy increasing sequences
// Sort by endpoint. We need segment tree supporting range add and range sum.
vector<ll> solve(const vector<int>& h, vector<pair<int, int>> que) {
	int n = h.size();
	int q = que.size();
	SegTree seg(n);

	// Find previous point that is higher than current index
	vector<int> sta;
	vector<int> pre(n);
	for (int i = 0; i < n; ++i) {
		while((! sta.empty()) && (h[sta.back()] < h[i])) sta.pop_back();
		if (! sta.empty()) pre[i] = sta.back() + 1;
		else pre[i] = 0;
		sta.push_back(i);
	}

	// for (int i = 0; i < n; ++i) cerr << h[i] << ' '; cerr << '\n';
	// for (int i = 0; i < n; ++i) cerr << pre[i] << ' '; cerr << '\n';
	
	// Sort queries by endpoint
	vector<pair<int, int>> qs(q);
	for (int j = 0; j < q; ++j) qs[j] = {-que[j].second, j};
	sort(qs.begin(), qs.end());

	// Initialize segtree values
	for (int i = 0; i < n; ++i) {
		seg.addRange(pre[i], i-1, 1);
		// cerr << "\tincrement " << pre[i] << ' ' << i-1 << '\n';
	}

	// Answer queries
	vector<ll> ans(q);

	int b = n-1;
	for (auto pr : qs) {
		int j = pr.second;
		// cerr << "Answering query " << j << ": " << que[j].first << ' ' << que[j].second << '\n';

		while(b > que[j].second) {
			// cerr << "\tdecrement " << pre[b] << ' ' << b-1 << '\n';
			seg.addRange(pre[b], b-1, -1);
			--b;
		}
		ans[j] = seg.sumRange(que[j].first, que[j].second);
		// cerr << "query " << que[j].first << ' ' << que[j].second << ": " << ans[j] << '\n';
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> h(n);
	for (int i = 0; i < n; ++i) cin >> h[i];
	
	vector<pair<int, int>> que(q);
	for (int i = 0; i < q; ++i) cin >> que[i].first;
	for (int i = 0; i < q; ++i) cin >> que[i].second;
	for (int i = 0; i < q; ++i) {
		--que[i].first; --que[i].second;
	}

	vector<ll> res1 = solve(h, que);
	
	reverse(h.begin(), h.end());
	vector<pair<int, int>> rev_que(q);
	for (int i = 0; i < q; ++i) {
		rev_que[i].first = n-1 - que[i].second;
		rev_que[i].second = n-1 - que[i].first;
	}

	vector<ll> res2 = solve(h, rev_que);

	for (int i = 0; i < q; ++i) {
		int len = que[i].second - que[i].first + 1;
		ll res = res1[i] + res2[i] + len;
		// cerr << res1[i] << ' ' << res2[i] << ' ' << len << ": ";
		cout << res << ' ';
		// cerr << '\n';
	}
	cout << '\n';
}