#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
	int n, m;
	cin >> n >> m;

	vector<int> as(n);
	for(int& a : as) cin >> a;
	sort(as.begin(), as.end());
	
	vector<pair<int, int>> ord;
	for (int i = 0; i < n;) {
		int j = i;
		for (ord.emplace_back(0, as[i]); j < n && as[j] == as[i]; ++j) ++ord.back().first;
		i = j;
	}
	sort(ord.rbegin(), ord.rend());
	
	// There are at most sqrt(n) possible counts
	// For every value, for every count, loop down until you find a non-banned pair
	int k = ord.size();
	vector<int> cou0;
	for (int i = 0; i < k; ++i) {
		if (i == 0 || ord[i-1].first != ord[i].first) cou0.push_back(i);
	}

	vector<pair<int, int>> bans(2*m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		bans[2*i] = {a, b};
		bans[2*i+1] = {b, a};
	}
	sort(bans.begin(), bans.end());

	ll res = 0;
	for (int i = 0; i < k; ++i) {
		int c = ord[i].first;
		int v = ord[i].second;
		for (int j : cou0) {
			for (int ind = j; ind < k && ord[ind].first == ord[j].first; ++ind) {
				if (ind == i) continue;

				pair<int, int> pr = {v, ord[ind].second};
				int x = bins(bans, pr);
				if (x < bans.size() && bans[x] == pr) continue;
				
				ll off = ((ll)c + ord[ind].first) * ((ll)v + ord[ind].second);
				res = max(res, off);
				break;
			}
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