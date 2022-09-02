#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modAdd(ll a, ll b) {
	return a + b >= MOD ? a + b - MOD : a + b;
}
ll modSub(ll a, ll b) {
	return a < b ? MOD + a - b : a - b;
}

const int N = 5 * (int)1e5;
int lst[N+1];
int fst[N+1];
int dp[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, m;
	cin >> n >> k >> m;

	vector<pair<pair<int, int>, int>> q(m);
	for (auto& pr : q) {
		cin >> pr.first.first >> pr.first.second >> pr.second;
		--pr.first.first; --pr.first.second;
	}

	ll res = 1;
	for (int j = 0; j < k; ++j) {
		// Select jth bits of numbers. The different bits can be selected independently of other bits.
		// All conditions are then of form "this interval contains only ones" or "this interval contains a zero"

		for (int i = 0; i < n; ++i) {
			lst[i] = -1;
			fst[i] = -1;
		}
		for (auto pr : q) {
			if (pr.second & (1 << j)) lst[pr.first.first] = max(lst[pr.first.first], pr.first.second);
			else fst[pr.first.second] = max(fst[pr.first.second], pr.first.first);
		}

		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				lst[i] = max(lst[i], lst[i-1]);
				fst[i] = max(fst[i], fst[i-1]);
			}
		}
		for (int i = n-1; i >= 0; --i) {
			if (lst[i] != -1 && lst[i] + 1 < n) lst[i] = max(lst[i], lst[lst[i] + 1]);
			if (lst[i] >= i && i > 0) fst[i-1] = max(fst[i-1], fst[i]);
		}

		bool fail = false;
		vector<int> inds = {-1};
		for (int i = 0; i < n; ++i) {
			if (lst[i] != -1 && fst[lst[i]] >= i) fail = true;
			if (lst[i] < i) inds.push_back(i);
		}

		if (fail) {
			res = 0;
			break;
		}

		int x = 0;
		for (int ind = 1; ind < inds.size(); ++ind) {
			int i = inds[ind];
			while(inds[x] < fst[i]) ++x;
			fst[ind - 1] = x;
		}

		// Queries of type "There must exist a zero in this interval" remain.
		// We maintain dp[a]: ways to select numbers such that the last 0 was at a and the prefix up to b works
		int a = 0;
		dp[0] = 1;
		ll sum = 1;
		for (int b = 1; b < inds.size(); ++b) {
			dp[b] = sum;
			sum = modAdd(sum, dp[b]);
			for (; a < fst[b-1]; ++a) sum = modSub(sum, dp[a]);
		}
		res = (res * sum) % MOD;
	}
	if (res < 0) res += MOD;
	cout << res << '\n';
}