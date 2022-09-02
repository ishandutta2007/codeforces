#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int C = 26;

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
		ll get(int a, int b) { return get(b) - get(a-1); }

		// Assuming prefix sums are non-decreasing, finds last i s.t. get(i) <= v
		int search(ll v) {
			int res = 0;
			for (int h = 1<<30; h; h >>= 1) {
				if ((res | h) < val.size() && val[res | h] <= v) {
					res |= h;
					v -= val[res];
				}
			}
			return res - 1;
		}
};

void solve() {
	int n;
	cin >> n;
	string str, tar;
	cin >> str >> tar;

	vector<vector<int>> pos(C, vector<int>());
	for (int i = 0; i < n; ++i) pos[str[i] - 'a'].push_back(i);
	for (int c = 0; c < C; ++c) reverse(pos[c].begin(), pos[c].end());
	
	Fenwick fenw(n);
	for (int i = 0; i < n; ++i) fenw.add(i, 1);

	ll res = INF, cur = 0;
	for (int i = 0; i < n; ++i) {
		int tc = tar[i] - 'a';
		for (int c = 0; c < tc; ++c) {
			if (pos[c].empty()) continue;
			res = min(res, cur + fenw.get(pos[c].back()) - 1);
		}
		if (pos[tc].empty()) break;
		cur += fenw.get(pos[tc].back()) - 1;
		fenw.add(pos[tc].back(), -1);
		pos[tc].pop_back();
	}
	if (res >= INF) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}