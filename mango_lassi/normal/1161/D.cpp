#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

int advance(int n, int j) {
	int r = n-1-j;
	return (r == j ? -1 : r);
}
ll track(int i, const string& str, int bn) {
	vector<int> szs = {bn-1, (int)str.size()-1};
	vector<int> dp = {1, 0};
	bool side = false; // in A?
	for (int j = i; j <= i;) {
		if (j == szs[side]) dp[0] = 0; // A/B must start with 1

		if (str[j] == '?') {
			dp[0] = (dp[0] + dp[1]) % MOD;
			dp[1] = dp[0];
		} else if (str[j] == '1') swap(dp[0], dp[1]);
		side ^= 1;

		if (j == szs[side]) dp[0] = 0; // A/B must start with 1
		if (j > szs[side]) return dp[0]; // Past end of B
		if (2*j == szs[side]) return (dp[0] + dp[1]) % MOD; // Don't turn around
		j = szs[side] - j;
	}
	return 1; // Prevent double-counting
}

ll count(const string& str, int bn) {
	int n = str.size();
	ll res = 1;
	for (int i = n-1; i >= bn; --i) {
		res = (res * track(i, str, bn)) % MOD;
	}
	return res;
}

ll solve(const string& str) {
	int n = str.size();
	ll res = 0;
	for (int bn = 1; bn < n; ++bn) {
		res = (res + count(str, bn)) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	ll ans = solve(str);
	cout << ans << '\n';
}