#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const ll INF = 2 * (ll)1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Always produce sword that finishes the earliest
	int n;
	cin >> n;

	vector<pair<ll, pair<ll, ll>>> evs(n);
	for (int i = 0; i < n; ++i) {
		ll a, b, t;
		cin >> a >> b >> t;
		evs[i] = {a, {-t, b}};
	}
	sort(evs.begin(), evs.end());

	priority_queue<pair<ll, ll>> act;
	ll res = 0, cur = 0;
	int ei = 0;
	while(true) {
		if (act.empty()) {
			if (ei == n) break;
			cur = evs[ei].first;
			act.push(evs[ei].second);
		}
		ll t = -act.top().first;
		ll off1 = (act.top().second - cur) / t;
		ll off2 = (ei >= n ? INF : (evs[ei].first - cur) / t);
		ll off = min(off1, off2);
		if (off > 0) {
			res += off;
			cur += t * off;
		} else if (off1 <= 0) {
			act.pop();
		} else if (off2 <= 0) {
			ll nxt = cur + t;
			while(ei < n && evs[ei].first < nxt) {
				nxt = min(nxt, evs[ei].first - evs[ei].second.first);
				act.push(evs[ei].second);
				++ei;
			}
			++res;
			cur = nxt;
		}
	}
	cout << res << '\n';
}