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


template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;

		int recf(int a, T v) const {
			while(a < n) a = 2*a + (seg[2*a] > v);
			return a - n;
		}
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}

		// Returns smallest i >= a s.t. val[i] <= v, or n if there is none
		int search(int a, T v) const {
			int b = 2*n, r = 2*n;
			for (a += n; a < b; a=(a+1)/2, b /= 2) {
				if ((a & 1) && seg[a] <= v) return recf(a, v);
				if ((b & 1) && seg[b-1] <= v) r = b-1;
			}
			return recf(r, v);
		}
		T get(int a, int b) const {
			T res = INF;
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void offer(int i, T v) {
			seg[i + n] = min(seg[i + n], v);
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n + 1, 0), dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> as[i];
		as[i] += as[i-1];
	}
	vector<ll> ord = as;
	sort(ord.begin(), ord.end());

	RangeMin<ll> seg0(vector<ll>(n + 1, INF)), seg1(vector<ll>(n + 1, INF));
	int zero_ind = bins(ord, as[0]);
	seg0.offer(zero_ind, 0),
	seg1.offer(zero_ind, 0);

	for (int i = 1; i <= n; ++i) {
		// Case 1: make a positive interval -> prefix sum at previous spot was strictly smaller
		int ind0 = bins(ord, as[i]);
		ll off0 = i - seg0.get(0, ind0 - 1);
		
		// Case 2: make 0-interval -> prefix sum is equal
		int ind1 = bins(ord, as[i] + 1);
		ll off1 = -seg1.get(ind0, ind1 - 1);
		
		// Case 3: negative interval
		dp[i] = max(dp[i-1] - 1, max(off0, off1));
		seg0.offer(ind0, i - dp[i]);
		seg1.offer(ind0, - dp[i]);
	}
	cout << dp[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}