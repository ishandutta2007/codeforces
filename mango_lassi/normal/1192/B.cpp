#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class SegTree {
	private:
		vector<ll> seg;
		vector<ll> tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] += v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		void recAddRange(int a, int b, ll v, int i, int ia, int ib) {
			if (ib < a || b < ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recAddRange(a, b, v, 2*i, ia, im);
				recAddRange(a, b, v, 2*i+1, im+1, ib);
				seg[i] = max(seg[2*i], seg[2*i+1]);
			}
		}
		ll recGetMax(int a, int b, int i, int ia, int ib) {
			if (ib < a || b < ia) return 0;
			if (a <= ia && ib <= b) return seg[i];
			else {
				push(i);
				int im = (ia + ib) >> 1;
				return max(
					recGetMax(a, b, 2*i, ia, im),
					recGetMax(a, b, 2*i+1, im+1, ib));
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h <<= 1;
			seg.resize(2*h, 0);
			tag.resize(h, 0);
		}
		void addRange(int a, int b, ll v) {
			recAddRange(a, b, v, 1, 0, h-1);
		}
		ll getMax(int a, int b) {
			return recGetMax(a, b, 1, 0, h-1);
		}
};
class TwoMaxes {
	private:
		vector<pair<ll, ll>> seg;
		int h = 1;

		pair<ll, ll> combine(pair<ll, ll> le, pair<ll, ll> ri) {
			if (le < ri) swap(le, ri);
			if (le.second >= ri.first) return le;
			else return {le.first, ri.first};
		}
	public:
		TwoMaxes(int n) {
			while(h < n) h <<= 1;
			seg.resize(2*h, {0, 0});
		}
		void setVal(int i, ll v) {
			seg[i + h] = {v, 0};
			for (i += h; i > 1; i >>= 1) {
				seg[i >> 1] = combine(seg[i], seg[i ^ 1]);
			}
		}
		pair<ll, ll> getMaxes() const {
			return seg[1];
		}
};

class HLD {
	private:
		vector<int> ind, siz, root;

		int dfs(int i, int r, int& j, const vector<vector<int>>& conns) {
			ind[i] = j;
			root[i] = r;
			++j;
			for (auto t : conns[i]) {
				siz[i] += dfs(t, r, j, conns);
			}
			return siz[i];
		}
	public:
		HLD(const vector<int>& par) : ind(par.size()), siz(par.size(), 1), root(par.size()) {
			int n = par.size();
			vector<vector<int>> conns(n);
			for (int i = 0; i < n; ++i) {
				if (par[i] != -1) conns[par[i]].push_back(i);
			}
			int j = 0;
			for (int i = 0; i < n; ++i) {
				if (par[i] == -1) {
					dfs(i, i, j, conns);
				}
			}
		}
		pair<int, int> stQuery(int i) {
			return {ind[i], ind[i]+siz[i]-1};
		}
		int getRoot(int i) { return root[i]; }
};

class Solver {
	private:
		HLD hld;
		SegTree seg;
		vector<TwoMaxes> maxes;
		vector<ll> pw;
		vector<int> maxes_ind;
		vector<int> maxes_loc;
	public:
		Solver(int n, const vector<int>& par, vector<int>& gi, vector<int>& gc, vector<int>& gs, const vector<ll>& par_w)
				: hld(par), seg(n), pw(par_w), maxes_ind(gi), maxes_loc(gc) {
			for (int i = 0; i < n; ++i) {
				auto range = hld.stQuery(i);
				seg.addRange(range.first, range.second, pw[i]);
			}

			for (int j = 0; j < gs.size(); ++j) {
				maxes.emplace_back(gs[j]);
			}
			maxes.emplace_back(gs.size());

			for (int i = 0; i < n; ++i) {
				if (par[i] == -1) {
					auto range = hld.stQuery(i);
					ll off = seg.getMax(range.first, range.second);

					int ai = maxes_ind[i];
					int bi = maxes_loc[i];
					if (bi != -1) {
						maxes[ai].setVal(bi, off);
						auto mx = maxes[ai].getMaxes();
						maxes.back().setVal(ai, mx.first + mx.second);
					}
				}
			}
		}
		void upd(int i, ll v) {
			ll d = v - pw[i];
			pw[i] = v;

			auto range = hld.stQuery(i);
			seg.addRange(range.first, range.second, d);

			int p = hld.getRoot(i);
			range = hld.stQuery(p);
			ll off = seg.getMax(range.first, range.second);

			int ai = maxes_ind[p];
			int bi = maxes_loc[p];
			if (bi != -1) {
				maxes[ai].setVal(bi, off);
				auto mx = maxes[ai].getMaxes();
				maxes.back().setVal(ai, mx.first + mx.second);
			}
		}
		ll get() {
			return maxes.back().getMaxes().first;
		}
};

struct CentroidDecomp {
	vector<int> layer;
	vector<int> siz;
	vector<vector<int>> conns;
	vector<vector<int>> par;
	int h = 0;
	
	bool dfs(int i, int p, int d, int n) {
		siz[i] = 1;
		for (auto t : conns[i]) {
			if (t == p || layer[t] != -1) continue;
			if (dfs(t, i, d, n)) return true;
			siz[i] += siz[t];
		}
		if (2*siz[i] >= n) {
			h = max(h, d+1);
			layer[i] = d;
			for (auto t : conns[i]) {
				if (layer[t] != -1) continue;
				int sub_n = (t == p ? n - siz[i] : siz[t]);
				dfs(t, -1, d+1, sub_n);
			}
			siz[i] = n;
			return true;
		} else return false;
	}
	void dfs2(int i, int p, int d) {
		if (layer[i] <= d) return;
		par[d][i] = p;
		for (auto t : conns[i]) {
			if (t != p) dfs2(t, i, d);
		}
	}
	CentroidDecomp(const vector<vector<int>>& c)
			: layer(c.size(), -1), siz(c.size()), conns(c) {
		int n = conns.size();
		dfs(0, -1, 0, n);

		par.resize(h);
		for (int d = 0; d < h; ++d) {
			par[d].resize(n, -1);
			for (int i = 0; i < n; ++i) {
				if (layer[i] == d) {
					for (auto t : conns[i]) dfs2(t, i, d);
				}
			}
		}
	}
};

struct Edge {
	int a, b;
	ll c;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	ll w;
	cin >> n >> q >> w;

	vector<vector<int>> conns(n);
	vector<Edge> edges(n-1);
	for (int j = 0; j < n-1; ++j) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		--a; --b;
		edges[j] = {a, b, c};
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	CentroidDecomp cdc(conns);
	vector<Solver> solvers;
	for (int d = 0; d < cdc.h; ++d) {
		vector<int> mp(n, -1);
		vector<int> gi(n, -1);
		vector<int> gc(n, -1);
		vector<int> gs;

		for (int i = 0; i < n; ++i) {
			int p = cdc.par[d][i];
			if (p != -1 && cdc.par[d][p] == -1) {
				if (gi[p] == -1) {
					gi[p] = gs.size();
					gs.push_back(0);
				}
				gi[i] = gi[p];
				gc[i] = gs[gi[i]];
				++gs[gi[i]];
			} else mp[i] = p;
		}
		vector<ll> pw(n, 0);
		for (auto& ed : edges) {
			if (cdc.par[d][ed.a] == ed.b) swap(ed.a, ed.b);
			if (cdc.par[d][ed.b] == ed.a) pw[ed.b] = ed.c;
		}
		solvers.emplace_back(n, mp, gi, gc, gs, pw);
	}

	ll res = 0;
	for (int qi = 0; qi < q; ++qi) {
		ll et, vt;
		cin >> et >> vt;

		int ei = (et + res) % (n-1);
		ll vi = (vt + res) % w;

		res = 0;
		auto& ed = edges[ei];
		for (int d = 0; d < cdc.h; ++d) {
			if (cdc.par[d][ed.a] == ed.b) swap(ed.a, ed.b);
			if (cdc.par[d][ed.b] == ed.a) {
				solvers[d].upd(ed.b, vi);
			}
			res = max(res, solvers[d].get());
		}
		cout << res << '\n';
	}
}