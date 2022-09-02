#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

class SegTree {
	private:
		const ll NEUT = 4 * (ll)1e18; 
		vector<pair<ll, ll>> seg; // Range min val + cost, range min cost
		vector<pair<ll, ll>> tag; // Range add, range cap
		int h = 1;

		void apply(int i, ll add, ll cap) {
			seg[i].first = min(seg[i].first + add, cap + seg[i].second);
			if (i < h) {
				tag[i].first += add;
				tag[i].second = min(tag[i].second + add, cap);
			}
		}
		void push(int i) {
			apply(2*i, tag[i].first, tag[i].second);
			apply(2*i+1, tag[i].first, tag[i].second);
			tag[i].first = 0;
			tag[i].second = NEUT;
		}
		void update(int i) {
			seg[i].first = min(seg[2*i].first, seg[2*i+1].first);
			seg[i].second = min(seg[2*i].second, seg[2*i+1].second);
		}
		void setVal(int x, pair<ll, ll> vc, int i, int ia, int ib) {
			if (ib <= x || x < ia) return;
			if (ia == x && x + 1 == ib) {
				seg[i] = vc;
			} else {
				push(i);
				int im = (ia + ib) >> 1;
				setVal(x, vc, 2*i, ia, im);
				setVal(x, vc, 2*i+1, im, ib);
				update(i);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, make_pair(INF, INF));
			tag.resize(h, make_pair(0ll, INF));
		}
		void apply(ll add, ll cap) {
			apply(1, add, cap);
		}
		ll get() {
			return seg[1].first;
		}
		void setVal(int x, pair<ll, ll> vc) {
			setVal(x, vc, 1, 0, h);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> vals(3, vector<ll>(n));
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> vals[y][x];
			vals[y][x] *= -1;
		}
	}

	vector<pair<int, pair<int, ll>>> evs;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll x;
		cin >> a >> b >> x;
		--a; --b;

		evs.emplace_back(a-1, make_pair(i, INF));
		evs.emplace_back(b, make_pair(i, x));
	}
	sort(evs.rbegin(), evs.rend());
	
	ll cur_sum = 0;
	SegTree seg(m);
	vector<ll> dp(n + 1, INF);
	for (int i = n-1, j = 0; i >= 0; --i) {
		cur_sum += vals[2][i];
		for(; j < evs.size() && evs[j].first == i; ++j) {
			seg.setVal(evs[j].second.first, make_pair(min(cur_sum, dp[i + 1]) + evs[j].second.second, evs[j].second.second));
		}
		seg.apply(vals[1][i], vals[1][i] + cur_sum);
		dp[i] = seg.get();
	}

	cur_sum = 0;
	ll res = INF;
	for (int i = 0; i < n; ++i) {
		cur_sum += vals[0][i];
		res = min(res, dp[i] + cur_sum);
	}
	cout << -res << '\n';
}