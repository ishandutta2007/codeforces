#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int mod;

// Builds the z-array (with shifts)for the vector v
// for i > 0, res[i] is the maximum value such that
// v[0, res[i]) = k + v[i, i+res[i])
// for some integer k. note the half open interval.
// time complexity: O(n)
vector<int> shiftArray(const vector<int>& v) {
	int n = v.size();
	vector<int> res(n, 0);
	int l = -1;
	int r = -1;

	for (int i = 1; i < n; ++i) {
		int k = v[0] - v[i];
		if (i <= r) res[i] = min(res[i - l], r - i);
		for (; (r <= i + res[i]) && (i + res[i] < n); ++res[i]) {
			if (v[res[i]] != k + v[i + res[i]]) break;
			l = i;
			r = i+res[i];
		}
	}
	return res;
}

vector<bool> getCans(const vector<int>& vals) {
	int n = vals.size();
	
	vector<int> rep(2*n);
	for (int i = 0; i < n; ++i) rep[i] = vals[i];
	for (int i = 0; i < n; ++i) rep[2*n-1-i] = -vals[i];
	

	vector<int> arr = shiftArray(rep);
	
	vector<bool> cans(n+1, false);
	cans[0] = true;
	for (int len = 1; len <= n; ++len) {
		if (arr[2*n - len] >= (len+1) / 2) cans[len] = true;
	}
	return cans;
}

int main() {
	// What are the zeroes of the thing when shifted by 

	// A number z is only unavailable if for all x, exists y such that x+y = z (mod M)
	// if we weren't allowed to go modulo on this, it would be trivial: smallest and largest must be a pair, and that is the only fail that can exist.
	// Since we can go modulo, it's not so easy. Assume that some of the integers make their pair go over. This is always some suffix of the integers, when sorted
	// (why?) only integers that are over our target can go modulo, and exactly those do. The numbers larger than our target pair with other numbers larger than the target.
	// Therefore we can just loop the interval of numbers that is larger than the target

	// To find out which shifts work for the prefix, we'll use z-algorithm on the following string:
	// a b c d e f $ f e d c b a
	// Similarly, to find out which shifts work for the suffix, we'll use z-algorithm on the following string:
	// f e d c b a $ a b c d e f

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> mod; // mod defined globally

	vector<int> vals(n);
	vector<int> inv(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int i = 0; i < n; ++i) inv[i] = vals[n-1-i];

	/*
	vector<int> arr = shiftArray(vals);
	for (auto v : arr) cout << v << ' '; cout << '\n';
	*/

	vector<bool> pref_cans = getCans(vals);
	vector<bool> suff_cans = getCans(inv);
	reverse(suff_cans.begin(), suff_cans.end());

	/*
	for (auto it : pref_cans) cout << it; cout << '\n';
	for (auto it : suff_cans) cout << it; cout << '\n';
	*/

	vector<int> res;
	for (int len = 0; len <= n; ++len) {
		if (pref_cans[len] && suff_cans[len]) {
			if (len == 0 || len == n) {
				res.push_back((vals[0] + vals[n-1]) % mod);
			} else {
				int pref_val = (vals[0] + vals[len-1]) % mod;
				int suff_val = (vals[len] + vals[n-1]) % mod;
				if (pref_val == suff_val) res.push_back(pref_val);
			}
		}
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	cout << res.size() << '\n';
	for (auto it : res) cout << it << ' '; cout << '\n';
}