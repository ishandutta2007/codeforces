#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;
using ll = long long;

class HLD {
	private:
		vector<int> par;
		vector<int> siz;
		vector<int> ind;
		vector<int> cmp;
	public:
		HLD(const vector<int>& p) : par(p), siz(p.size(), 1), ind(p.size()), cmp(p.size(), 0) {
			int n = p.size();
			for (int i = n-1; i > 0; --i) siz[par[i]] += siz[i];

			vector<int> aux = siz;
			for (int i = 1; i < n; ++i) {
				if (2*siz[i] >= siz[par[i]]) {
					ind[i] = ind[par[i]] + 1;
					cmp[i] = cmp[par[i]];
				} else {
					aux[par[i]] -= siz[i];
					ind[i] = aux[par[i]];
					cmp[i] = i;
				}
				aux[i] += ind[i];
			}
		}
		vector<pair<int, int>> pathQuery(int i) {
			vector<pair<int, int>> res;
			while(i != -1) {
				res.push_back({ind[cmp[i]], ind[i]});
				i = par[cmp[i]];
			}
			return res;
		}
		pair<int, int> stQuery(int i) {
			return {ind[i], ind[i] + siz[i] - 1};
		}
		int indQuery(int i) { return ind[i]; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> par(n, -1);
	for (int i = 1; i < n; ++i) {
		cin >> par[i];
		--par[i];
	}
	
	HLD hld(par);

	vector<tuple<int, int, ll>> fruits(m);
	for (int j = 0; j < m; ++j) {
		int x, r;
		ll v;
		cin >> x >> r >> v;
		fruits[j] = {r, -(x-1), v};
	}
	sort(fruits.begin(), fruits.end());

	ll res = 0;
	vector<ll> inc(n, 0);
	set<int> act;
	for (auto tp : fruits) {
		int x, r;
		ll v;
		tie(r, x, v) = tp;
		x *= -1;

		ll add = v;
		vector<pair<int, int>> path = hld.pathQuery(x);
		for (auto pr : path) {
			while(add > 0) {
				auto it = act.upper_bound(pr.second);
				if (it == act.begin()) break;
				--it;
				int j = (*it);
				if (j < pr.first) break;

				if (inc[j] > add) {
					inc[j] -= add;
					add = 0;
				} else {
					add -= inc[j];
					inc[j] = 0;
					act.erase(it);
				}
			}
		}
		res += add;

		int j = hld.indQuery(x);
		inc[j] = v;
		act.insert(j);
	}
	cout << res << '\n';
}