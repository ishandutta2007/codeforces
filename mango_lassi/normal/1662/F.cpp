#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

class RangeMin {
	private:
		vector<ll> seg;
		int n;
	public:	
		RangeMin(const vector<ll>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		ll get(int a, int b) const {
			ll res = INF;
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void set(int i, ll v) {
			seg[i + n] = v;
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

vector<ll> getPrev(const vector<int>& rs) {
	int n = rs.size();
	RangeMin act(vector<ll>(n, INF));
	priority_queue<pair<int, int>> que;
	vector<ll> pre(n);
	for (int i = 0; i < n; ++i) {
		while(! que.empty() && -que.top().first < i) {
			int j = que.top().second;
			que.pop();
			act.set(j, INF);
		}
		act.set(i, i);
		pre[i] = act.get(max(0, i - rs[i]), i);
		que.emplace(-(i + rs[i]), i);
	}
	return pre;
}

pair<int, int> expand(int le, int ri, const RangeMin& le_seg, const RangeMin& ri_seg) {
	int nxt_le = le_seg.get(le, ri);
	int nxt_ri = -ri_seg.get(le, ri);
	return {nxt_le, nxt_ri};
}

void solve() {
	int n, al, bl;
	cin >> n >> al >> bl;
	--al; --bl;

	vector<int> rs(n);
	for (int& r : rs) cin >> r;

	if (al == bl) {
		cout << 0 << '\n';
	} else {
		vector<ll> le = getPrev(rs);
		reverse(rs.begin(), rs.end());
		vector<ll> ri = getPrev(rs);
		reverse(ri.begin(), ri.end());
		for (ll& v : ri) v = -(n-1 - v);

		int ar = al, br = bl;
		RangeMin le_seg(le), ri_seg(ri);

		int res = 1;
		for (;; ++res) {
			int nxt_al, nxt_ar, nxt_bl, nxt_br;
			tie(nxt_al, nxt_ar) = expand(al, ar, le_seg, ri_seg);
			tie(nxt_bl, nxt_br) = expand(bl, br, le_seg, ri_seg);
			if (nxt_ar < bl || br < nxt_al) {
				al = nxt_al;
				ar = nxt_ar;
			} else if (nxt_br < al || ar < nxt_bl) {
				bl = nxt_bl;
				br = nxt_br;
			} else {
				break;
			}
		}
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}