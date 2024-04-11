#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Segment tree for query: "historic range sum" and operation: "set range to 0/1"
class SegTree {
	private:
		struct Operation {
			int t0, t1, v, sum;
			Operation() : t0(0), t1(0), v(-1), sum(0) {}
			Operation(int t) : t0(t), t1(t), v(-1), sum(0) {}
			Operation(int t, int val) : t0(t), t1(t), v(val), sum(0) {}
			Operation(const Operation& a, const Operation& b) {
				if (a.v == -1) {
					t0 = b.t0;
					t1 = b.t1;
					v = b.v;
					sum = b.sum;
				} else {
					t0 = a.t0;
					t1 = b.t1;
					v = (b.v == -1 ? a.v : b.v);
					sum = a.sum + b.sum + (b.t0 - a.t1) * a.v;
				}
			}
		};
		vector<ll> cur, hist;
		vector<Operation> ops;
		int h = 1, cur_t = 0;
		
		// Returns length of interval corresponding to position i
		ll len(int i) { return h >> (31 - __builtin_clz(i)); }
		
		void apply(int i, Operation op) {
			hist[i] += ((op.t0 - ops[i].t1) * cur[i]) + (len(i) * op.sum);
			if (op.v != -1) {
				if (op.v == 0) cur[i] = 0;
				else cur[i] = len(i);
			}
			ops[i] = Operation(ops[i], op);
		}
		void push(int i) {
			apply(2*i, ops[i]);
			apply(2*i + 1, ops[i]);
			ops[i].t0 = ops[i].t1;
			ops[i].sum = 0;
			ops[i].v = -1;
		}

		ll recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return 0;
			if (a <= ia && ib <= b) return hist[i];
			
			push(i);
			int im = (ia + ib) >> 1;
			return recGet(a, b, 2*i, ia, im) + recGet(a, b, 2*i+1, im, ib);
		}
		void recApply(int a, int b, const Operation& op, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, op);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(a, b, op, 2*i, ia, im);
				recApply(a, b, op, 2*i+1, im, ib);
				cur[i] = cur[2*i] + cur[2*i+1];
				hist[i] = hist[2*i] + hist[2*i+1];
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			hist.resize(2*h, 0);
			cur.resize(2*h, 0);
			ops.resize(2*h);
		}
		ll rangeSum(int a, int b) {
			ll res = recGet(a, b+1, 1, 0, h);
			// cerr << "Get sum " << a << ' ' << b << ": " << res << '\n';
			return res;
		}
		void rangeSet(int a, int b, int v) {
			// cerr << "Set range " << a << ' ' << b << " to " << v << '\n';
			Operation op(cur_t, v);
			recApply(a, b+1, op, 1, 0, h);
		}
		void advance(int t = 1) {
			// cerr << "Advance time by " << t << '\n';
			cur_t += t;
			apply(1, Operation(cur_t));
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	vector<int> rev_as(n + 1);
	for (int i = 0; i < n; ++i) rev_as[as[i]] = i;

	vector<ll> ans(q, 0);
	vector<pair<pair<int, int>, int>> qs(q);
	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		qs[qi] = {{b, a}, qi};
	}
	sort(qs.begin(), qs.end());

	vector<int> offers(n, -1);
	vector<int> que_pos(n + 1, 0);
	vector<int> max_que = {-1};
	SegTree seg(n);
	for (int b = 0, j = 0; b < n; ++b) {
		// 1. Update range where this is the maximum
		while(max_que.back() >= 0 && as[max_que.back()] < as[b]) {
			int y = max_que.back();
			que_pos[y] = 0;
			max_que.pop_back();
			int x = max_que.back() + 1;
			seg.rangeSet(x, y, 0);
		}
		seg.rangeSet(max_que.back() + 1, offers[b], 1);

		que_pos[b] = max_que.size();
		max_que.push_back(b);

		// 2. Handle pairs
		for (int v = 1; v * as[b] <= n; ++v) {
			int off = rev_as[v];
			if (off >= b) continue;

			int t = v * as[b];
			if (rev_as[t] > b) {
				offers[rev_as[t]] = max(offers[rev_as[t]], off);
			} else {
				int ind = que_pos[rev_as[t]];
				int y = min(max_que[ind], off);
				if (y == -1) continue;

				int x = max_que[ind - 1] + 1;
				seg.rangeSet(x, y, 1);
			}
		}
		seg.advance();

		// Answer
		while(j < q && qs[j].first.first == b) {
			int a = qs[j].first.second;
			int qi = qs[j].second;
			ans[qi] = seg.rangeSum(a, b);
			++j;
		}

		/*
		cerr << "Current state: ";
		for (int i = 0; i < n; ++i) cerr << seg.rangeSum(i, i) << ' ';
		cerr << '\n';
		*/
	}
	for (ll v : ans) cout << v << ' '; cout << '\n';
}