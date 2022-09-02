#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

// Segment tree for range minimum and addition.
class SegTree {
	private:
		const ll NEUT = 4 * (ll)1e18; 
		vector<ll> seg, tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] += v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		ll combine(ll a, ll b) { return min(a, b); }

		ll recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT;
			if (a <= ia && ib <= b) return seg[i];
			push(i);
			int im = (ia + ib) >> 1;
			return combine(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
		void recApply(int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = combine(seg[2*i], seg[2*i+1]);
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
			tag.resize(h, 0);
		}
		ll rangeMin(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
		int findNext(int a, int b, ll v) { return recFind(a, b+1, v, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll p;
	cin >> n >> p;

	SegTree act(n);
	act.rangeAdd(0, n-1, 1);
	
	// Events:
	//	-i: passenger i is now ready to get water
	//	-n: The passenger currently getting water gets it
	priority_queue<pair<ll, int>> evs;
	for (int i = 0; i < n; ++i) {
		ll t;
		cin >> t;
		evs.push({-t, -i});
	}

	int j = 0; // event index
	int i = 0; // queue index
	vector<ll> res(n), que;
	while(! evs.empty()) {
		ll t = -evs.top().first;
		int ind = -evs.top().second;
		evs.pop();

		if (ind == n) {
			int x = que[i];
			res[x] = t;
			act.rangeAdd(x, n-1, -1);
			// cerr << t << ": " << x << " gets their water\n";

			++i;
			if (i < que.size()) evs.push({-(t + p), -n});
		} else {
			// cerr << t << ": " << ind << " gets ready to get water\n";
			act.rangeAdd(ind, ind, -1);
		}

		if (act.rangeMin(0, n-1) == 0) {
			int x = act.findNext(0, n-1, 0);
			// cerr << t << ": " << x << " moves into the queue\n";
			act.rangeAdd(x, n-1, 1);
			act.rangeAdd(x, x, 1);

			if (i == que.size()) evs.push({-(t + p), -n});
			que.push_back(x);
		}
	}
	for (auto v : res) cout << v << ' '; cout << '\n';
}