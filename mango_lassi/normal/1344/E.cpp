#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 1e9;

class RangeMin {
	private:
		vector<ll> seg;
		int n;

		int recf(int a, ll v) const {
			while(a < n) a = 2*a + (seg[2*a] > v);
			return a - n;
		}
	public:	
		RangeMin(const vector<ll>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}

		// Returns smallest i >= a s.t. val[i] <= v, or n if there is none
		int search(int a, ll v) const {
			int b = 2*n, r = 2*n;
			for (a += n; a < b; a=(a+1)/2, b /= 2) {
				if ((a & 1) && seg[a] <= v) return recf(a, v);
				if ((b & 1) && seg[b-1] <= v) r = b-1;
			}
			return recf(r, v);
		}
		ll get(int a, int b) const {
			ll res = 2*INF;
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

class HLD {
	private:
		vector<int> par, siz, cmp, ind, rev;

		int dfs1(int i, vector<vector<int>>& g) {
			for (auto& t : g[i]) if (t != par[i]) {
				par[t] = i;
				siz[i] += dfs1(t, g);
				if (siz[t] > siz[g[i][0]] || g[i][0] == par[i]) swap(t, g[i][0]);
			}
			return siz[i];
		}
		void dfs2(int i, int& x, const vector<vector<int>>& g) {
			ind[i] = x;
			++x;
			for (auto t : g[i]) if (t != par[i]) {
				cmp[t] = (x == ind[i]+1 ? cmp[i] : t);
				dfs2(t, x, g);
			}
		}
	public:
		// Assumes the tree is connected and r is the root
		HLD(vector<vector<int>> g, int r = 0)
				: par(g.size(), -1), siz(g.size(), 1), cmp(g.size(), r), ind(g.size()), rev(g.size()) {
			dfs1(r, g);
			int x = 0;
			dfs2(r, x, g);
			for (int i = 0; i < g.size(); ++i) rev[ind[i]] = i;
		}
		// Returns interval corresponding to the subtree of node i
		pair<int, int> subtree(int i) const {
			return {ind[i], ind[i] + siz[i] - 1};
		}
		int lca(int a, int b) const {
			for (;; b = par[cmp[b]]) {
				if (ind[b] < ind[a]) swap(a, b);
				if (ind[cmp[b]] <= ind[a]) return a;
			}
		}
		// Returns vertex one step down from a in direction of b, assuming a is a strict ancestor of b.
		int oneDown(int a, int b) const {
			while(true) {
				if (b == cmp[b]) {
					if (par[b] == a) return b;
					else b = par[b];
				} else {
					if (ind[cmp[b]] <= ind[a]) return rev[ind[a]+1];
					else b = cmp[b];
				}
			}
		}
		int revInd(int i) const { return rev[i]; }
};

const int N = 1e5;
vector<pair<int, ll>> conns[N];
ll dep[N];

void dfs(int i, int p, ll& cur, vector<ll>& times) {
	for (int ti = (int)conns[i].size() - 1; ti >= 0; --ti) {
		auto pr = conns[i][ti];
		int t = pr.first;
		if (t == p) continue;
		dep[t] = dep[i] + pr.second;
		dfs(t, i, cur, times);
	}
	times[i] = cur;
	++cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//	Trivial if we can get events "trains going from this station change direction"
	//	For every subtree, maintain previous train that arrived there
	//	We must change direction at the point where the target of that train and the current train diverges.

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		ll d;
		cin >> a >> b >> d;
		--a; --b;

		g[a].push_back(b);
		g[b].push_back(a);
		conns[a].emplace_back(b, d);
		conns[b].emplace_back(a, d);
	}

	HLD hld(g);

	ll cur = INF;
	vector<ll> tmp(n, -1);
	dfs(0, -1, cur, tmp);

	vector<ll> times(n);
	for (int i = 0; i < n; ++i) times[i] = tmp[hld.revInd(i)];
	RangeMin rm(times);

	// 1. Generate events
	vector<pair<ll, ll>> evs;

	for (int j = 0; j < m; ++j) {
		int tar;
		ll tim;
		cin >> tar >> tim;
		--tar;

		int r = 0;
		while(r != tar) {
			auto st = hld.subtree(r);
			ll prev_time = -rm.get(st.first + 1, st.second);
			int prev_ind = rm.search(st.first + 1, -prev_time);
			int prev_tar = hld.revInd(prev_ind);
			int next_r = hld.lca(tar, prev_tar);

			if (next_r == tar) break;
			else if (next_r != prev_tar) {
				ll arr_time = prev_time + dep[next_r]; // Time previous arrived at next_r
				evs.emplace_back(prev_time + dep[next_r] + 1, tim + dep[next_r]);
				r = hld.oneDown(next_r, tar);
			} else {
				r = next_r;
			}
		}
		int i = hld.subtree(tar).first;
		rm.set(i, -tim);
	}
	sort(evs.begin(), evs.end());

	// 2. Act greedily based on events
	int tot = 0;
	priority_queue<ll> que, hangs;

	bool fail = 0;
	int ind = 0;
	ll t = 1;
	while(true) {
		while (ind < evs.size() && evs[ind].first <= t) {
			que.push(-evs[ind].second);
			++ind;
		}

		if (que.empty()) {
			if (ind == evs.size()) {
				break; // succeed
			} else {
				t = evs[ind].first;
			}
		} else {
			if (-que.top() >= t) {
				while(! hangs.empty() && -hangs.top() < t) {
					hangs.pop();
				}
				hangs.push(que.top());
				que.pop();
				++tot;
				++t;
			} else {
				--t;
				fail = 1;
				break; // fail
			}
		}
	}
	if (fail) cout << t << ' ' << tot - hangs.size() << '\n';
	else cout << -1 << ' ' << evs.size() << '\n';
}