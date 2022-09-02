#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

void solve() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> acs(n);
	for (auto& pr : acs) cin >> pr.first >> pr.second;
	sort(acs.begin(), acs.end());

	// WLOG Assume sorted a_i
	// Cost = c_i + max(0, a_j - (a_i + c_i))
	// -> Given path from 1 to n, we pay 0 for all other edges
	// -> find min-cost path from 1 to n
	
	vector<ll> max_nxt(n);
	max_nxt[0] = acs[0].first + acs[0].second;
	for (int i = 1; i < n; ++i) max_nxt[i] = max(max_nxt[i-1], acs[i].first + acs[i].second);

	ll res = 0;
	for (int i = 0; i < n-1;) {
		int nxt = bins(acs, make_pair(max_nxt[i], INF)) - 1;
		if (nxt > i) i = nxt;
		else {
			res += acs[i+1].first - max_nxt[i];
			++i;
		}
	}
	for (int i = 0; i < n; ++i) res += acs[i].second;
	
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}