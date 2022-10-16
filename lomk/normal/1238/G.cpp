/*input
1
2 3 5 1
2 1 1
1 4 3

*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cerr << "[" << #x << "] ="; _co(x);}
void _co() {cerr << endl;}
template<typename T, typename... Ts> void _co(const T& value, const Ts&... values) {cerr << ' ' << value; _co(values...);}
template<typename T, typename... Ts> void co(const T& value, const Ts&... values) {cerr << "deb: " << value; _co(values...);}

struct Data {
	int time, amo, cost;
	Data(int _time, int _amo, int _cost): time(_time), amo(_amo), cost(_cost) {};
	bool operator < (const Data &that) const {
		return cost < that.cost;
	}
};


signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef in1code
	freopen("1test.inp", "r", stdin);
#endif
	int T; cin >> T;
	while (T--) {
		vector<Data> a;
		vector<int> all;
		int n, m, c, c0;

		cin >> n >> m >> c >> c0;
		loop(i, 1, n) {
			int x, y, z; cin >> x >> y >> z;
			a.push_back({x, y, z});
			all.push_back(x);
		}

		all.push_back(m - 1); all.push_back(0);
		sort(all.begin(), all.end()); all.resize(distance(all.begin(), unique(all.begin(), all.end())));
		a.push_back({0, c0, 0});
		sort(a.begin(), a.end(), [&](Data & X, Data & Y) {
			return X.time < Y.time;
		});

		multiset<Data> mst;
		int tInAll = 0, iter = 0, inTank = 0, ans = 0;
		bool cant = false;
		while (tInAll < all.size()) {
			for (; iter < a.size() && a[iter].time <= all[tInAll]; iter++) {
				mst.insert(a[iter]);
				inTank += a[iter].amo;
			}
			while (inTank > c) {
				auto cur = *mst.rbegin(); mst.erase((--mst.end()));
				int rem = min(inTank - c, cur.amo);
				cur.amo -= rem; inTank -= rem;
				if (cur.amo) mst.insert(cur);
			}

			int need = [&] {
				if (tInAll + 1 == all.size()) return 1LL;
				return all[tInAll + 1] - all[tInAll];
			}();

			while (need > 0) {
				if (mst.empty()) {
					cant = true;
					break;
				}
				auto cur = *mst.begin(); mst.erase(mst.begin());
				int buy = min(cur.amo, need);
				need -= buy; cur.amo -= buy; inTank -= buy;
				ans += buy * cur.cost;
				if (cur.amo) mst.insert(cur);
			}
			tInAll++;
		}
		if (cant) cout << -1 << endl;
		else cout << ans << endl;
	}

}