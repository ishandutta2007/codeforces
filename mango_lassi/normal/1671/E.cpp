#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	
	string str;
	cin >> str;

	map<pair<char, pair<int, int>>, int> inds;
	vector<int> val((1 << (n + 1)), 0);
	vector<ll> dp = {1};

	for (int j = (n - 1); j >= 0; --j) {
		int a = (1 << j), b = (1 << (j + 1));
		for (int x = a; x < b; ++x) {
			pair<char, pair<int, int>> code = {str[x - 1], {val[2*x], val[2*x+1]}};
			if (code.second.first > code.second.second) swap(code.second.first, code.second.second);
			if (inds.find(code) == inds.end()) {
				inds[code] = dp.size();

				ll off = dp[val[2*x]] * dp[val[2*x+1]] % MOD;
				if (val[2*x] != val[2*x+1]) off = (off * 2) % MOD;

				dp.push_back(off);
			}
			val[x] = inds[code];
		}
	}
	cout << dp[val[1]] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}