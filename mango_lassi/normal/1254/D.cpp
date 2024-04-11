#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

class CentroidDecomp {
	private:
		void setBit(int i, int ti, int bit) {
			for (auto& pr : dir[i]) {
				if (pr.first != ti) continue;
				pr.second |= bit;
				return;
			}
			dir[i].emplace_back(ti, bit);
		}
		int calcSiz(int i, int p, int cl) {
			if (lvl[i] < cl) return 0;
			siz[i] = 1;
			for (int ti = 0; ti < g[i].size(); ++ti) {
				if (g[i][ti] != p) siz[i] += calcSiz(g[i][ti], i, cl);
				else if (cl < lvl[i]) setBit(i, ti, 1 << cl);
			}
			return siz[i];
		}
		int centroid(int i, int p, int cl, int n) const {
			if (lvl[i] < cl) return -1;
			for (auto t : g[i]) {
				if (t == p) continue;
				int sub = centroid(t, i, cl, n);
				if (sub != -1) return sub;
			}
			return (2*siz[i] >= n ? i : -1);
		}
	public:
		const vector<vector<int>> g;
		vector<pair<int, int>> par;
		vector<vector<pair<int, int>>> dir;
		vector<int> siz, lvl;

		CentroidDecomp(const vector<vector<int>>& cn) : g(cn), par(cn.size()), dir(cn.size()), siz(cn.size()), lvl(cn.size(), cn.size()) {
			int n = calcSiz(0, -1, cn.size());
			int r = centroid(0, -1, 0, n);
			lvl[r] = 0;
			vector<int> que = {r};
			for (int j = 0; j < n; ++j) {
				int i = que[j];
				int m = calcSiz(i, -1, lvl[i]);
				for (int ei = 0; ei < g[i].size(); ++ei) {
					int t = g[i][ei];
					if (lvl[t] < lvl[i]) continue;

					int tr = centroid(t, i, lvl[i] + 1, siz[t]);
					par[tr] = {i, ei};
					lvl[tr] = lvl[i] + 1;
					que.push_back(tr);
				}
			}
		}
		// Returns list 
		vector<pair<pair<int, int>, int>> getPars(int i) {
			vector<pair<pair<int, int>, int>> res(lvl[i]);
			for (auto pr : dir[i]) {
				for (int v = pr.second; v; v &= v-1) {
					res[__builtin_ctz(v)].second = pr.first;
				}
			}
			for (int j = lvl[i]-1; j >= 0; --j, i = par[i].first) {
				res[j].first = par[i];
			}
			return res;
		}
};

int dfsSiz(int i, int p, vector<int>& siz, const vector<vector<int>>& g) {
	for (auto t : g[i]) {
		if (t != p) siz[i] += dfsSiz(t, i, siz, g);
	}
	return siz[i];
}

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

int edSiz(int a, int b, const vector<int>& siz, int n) {
	return (siz[a] < siz[b] ? siz[a] : n - siz[b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<vector<int>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	CentroidDecomp cdc(g);

	vector<int> siz(n, 1);
	dfsSiz(0, 0, siz, g);

	vector<ll> sum(n, 0), exa(n, 0);
	vector<vector<ll>> ed_sum(n);
	for (int i = 0; i < n; ++i) ed_sum[i].resize(g[i].size(), 0);

	ll mult = modPow(n, MOD-2);
	for (int j = 0; j < q; ++j) {
		int t, i;
		cin >> t >> i;
		--i;

		if (t == 1) {
			ll d;
			cin >> d;

			exa[i] += d;

			auto pars = cdc.getPars(i);
			for (auto pr : pars) {
				ll v = d * edSiz(i, g[i][pr.second], siz, n) % MOD;
				sum[pr.first.first] += v;
				ed_sum[pr.first.first][pr.first.second] += v;
			}
		} else {
			ll res = (n*exa[i] + sum[i]) % MOD;

			auto pars = cdc.getPars(i);
			for (auto pr : pars) {
				res += (sum[pr.first.first] - ed_sum[pr.first.first][pr.first.second]) % MOD;
				res += exa[pr.first.first] * edSiz(pr.first.first, g[pr.first.first][pr.first.second], siz, n) % MOD;
			}
			res = ((res % MOD) * mult) % MOD;
			if (res < 0) res += MOD;
			cout << res << '\n';
		}
	}
}