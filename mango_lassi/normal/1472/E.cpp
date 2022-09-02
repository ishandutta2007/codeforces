#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

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

	vector<pair<pair<ll, ll>, int>> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i].first.first >> vals[i].first.second;
		vals[i].first.first = INF - vals[i].first.first;
		vals[i].first.second = INF - vals[i].first.second;
		vals[i].second = i;
	}
	sort(vals.begin(), vals.end());

	vector<pair<ll, ll>> max_w(n+1);
	max_w[n] = {0, -1};
	for (int i = n-1; i >= 0; --i) {
		max_w[i] = max(max_w[i+1], {vals[i].first.second, vals[i].second});
	}

	vector<int> res(n, -1);
	for (int j = 0; j < n; ++j) {
		ll h = vals[j].first.first;
		ll w = vals[j].first.second;
		int ind = vals[j].second;
		int i0 = bins(vals, {{h+1, 0ll}, -1});
		int i1 = bins(vals, {{w+1, 0ll}, -1});
		if (max_w[i0].first > w) res[ind] = max_w[i0].second;
		if (max_w[i1].first > h) res[ind] = max_w[i1].second;
	}
	for (auto v : res) cout << (v == -1 ? -1 : v + 1) << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}