#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

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

const ll INF = 1e18;
const int H = (int)1e6 + 10;
vector<pair<int, int>> wp, ar;
vector<pair<pair<int, int>, int>> mst;

ll recSolve(int a0, int a1, int b0, int b1, int c0, int c1, Fenwick& fenw) {
	int am = (a0 + a1) / 2;
	int cm = c0;
	while(cm <= c1 && mst[cm].first.first < wp[am].first) {
		fenw.add(mst[cm].first.second, mst[cm].second);
		++cm;
	}

	// Weapon "am"
	pair<ll, int> best = {-INF, -1};
	for (int j = b0; j <= b1; ++j) {
		ll val = fenw.get(ar[j].first - 1);
		ll sub = wp[am].second + ar[j].second;
		best = max(best, {val - sub, j});
	}
	int bm = best.second;
	ll res = best.first;

	// Stronger weapon
	if (am + 1 <= a1) res = max(res, recSolve(am+1, a1, bm, b1, cm, c1, fenw));

	for (int j = c0; j < cm; ++j) {
		fenw.add(mst[j].first.second, -mst[j].second);
	}

	// Weaker weapon
	if (am - 1 >= a0) res = max(res, recSolve(a0, am-1, b0, bm, c0, cm - 1, fenw));

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	wp.resize(n);
	ar.resize(m);
	mst.resize(k);

	for (auto& pr : wp) cin >> pr.first >> pr.second;
	for (auto& pr : ar) cin >> pr.first >> pr.second;
	sort(wp.begin(), wp.end());
	sort(ar.begin(), ar.end());

	for (auto& pr : mst) cin >> pr.first.first >> pr.first.second >> pr.second;
	sort(mst.begin(), mst.end());
	
	Fenwick fenw(H);
	ll res = recSolve(0, n-1, 0, m-1, 0, k-1, fenw);
	cout << res << '\n';
}