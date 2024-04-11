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

int countWorks(const vector<ll>& as, ll sum, ll len) {
	int low = 0;
	int high = (int)as.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (as[mid] * len >= sum) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	// cerr << "CountWorks(" << sum << ' ' << len << "): " << low << '\n';
	return low;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.rbegin(), as.rend());

	vector<vector<ll>> bs(m);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		bs[i].resize(k);
		for (ll& v : bs[i]) cin >> v;
	}

	vector<int> pfs(m);
	for (int i = 0; i < m; ++i) {
		ll sum = 0, len = bs[i].size();
		for (ll v : bs[i]) sum += v;

		int wk = countWorks(as, sum, len);
		pfs[i] = wk;
	}
	sort(pfs.begin(), pfs.end());
	
	bool fail = 0;
	int lo = m, hi = -1;
	for (int i = 0; i < m; ++i) {
		if (pfs[i] == i) {
			lo = min(lo, i);
			hi = max(hi, i);
		}
		if (pfs[i] < i) fail = 1;
	}


	if (fail == 1) {
		// NO removal can work
		// cerr << "Cat 0\n";
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < bs[i].size(); ++j) cout << 0;
		}
		cout << '\n';
	} else if (lo < m) {
		// cerr << "Cat 1\n";

		// Must change some group with at most lo working teachers, such that it has at least hi + 1 working teachers after the change
		for (int i = 0; i < m; ++i) {
			ll sum = 0, len = bs[i].size();
			for (ll v : bs[i]) sum += v;
			int cur = countWorks(as, sum, len);

			if (cur <= lo) {
				for (int j = 0; j < bs[i].size(); ++j) {
					ll v = bs[i][j];
					int off = countWorks(as, sum - v, len - 1);
					cout << (off > hi);
				}
			} else {
				for (int j = 0; j < bs[i].size(); ++j) cout << 0;
			}
		}
		cout << '\n';
	} else {
		vector<int> tcs;
		for (int i = 0; i < m; ++i) {
			if (pfs[i] == i + 1) tcs.push_back(i + 1);
		}
		if (! tcs.empty()) {
			// cerr << "Cat 2\n";
			for (int i = 0; i < m; ++i) {
				ll sum = 0, len = bs[i].size();
				for (ll v : bs[i]) sum += v;
				int cur = countWorks(as, sum, len);
				int ind0 = bins(tcs, cur);

				for (int j = 0; j < bs[i].size(); ++j) {
					ll v = bs[i][j];
					int off = countWorks(as, sum - v, len - 1);
					int ind1 = bins(tcs, off);
					cout << ((off > 0) && (ind0 <= ind1));
				}
			}
			cout << '\n';
		} else {
			// cerr << "Cat 3\n";
			// Only need to make sure some teacher works after change
			for (int i = 0; i < m; ++i) {
				ll sum = 0, len = bs[i].size();
				for (ll v : bs[i]) sum += v;

				for (int j = 0; j < bs[i].size(); ++j) {
					ll v = bs[i][j];
					int off = countWorks(as, sum - v, len - 1);
					cout << (off > 0);
				}
			}
			cout << '\n';
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}