#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

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
	int h, w;
	cin >> h >> w;

	vector<pair<int, int>> tm(h*w);
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int i = x + y * w;
			cin >> tm[i].first;
			tm[i].second = i;
		}
	}
	sort(tm.begin(), tm.end());
	
	vector<pair<int, pair<int, int>>> places(h*w);
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int i = x + y * w;
			places[i] = {tm[i].first, {y, -x}};
		}
	}
	sort(places.begin(), places.end());

	vector<int> times(h*w);
	for (int i = 0; i < h*w; ++i) {
		int y = places[i].second.first;
		int x = -places[i].second.second;
		times[x + y * w] = tm[i].second;
	}

	ll res = 0;
	Fenwick fenw(h*w);
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			int v = times[x + y * w];
			res += fenw.get(v);
			fenw.add(v, 1);
		}
		for (int x = 0; x < w; ++x) {
			int v = times[x + y * w];
			fenw.add(v, -1);
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}