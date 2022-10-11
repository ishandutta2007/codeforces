//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstdio>

#define FAST ios_base::sync_with_stdio(NULL); cin.tie(nullptr); cout.tie(nullptr)
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FIXED cout << fixed << setprecision(10)
#define all(a) begin(a), end(a)
#define pb(a) push_back(a)
#define sz(a) a.size()
#define mp(a, b) make_pair(a, b)

typedef long long ll;
typedef long double ld;

using namespace std;

const ll inf = 1e18;

ll n, a, b;
string s;

ll get() {
	vector <vector <ll>> dp(n + 1, vector <ll>(2, inf));
	dp[0][0] = b;
	for (int i = 1; i < n; i++) {
		if (s[i] == '1') {
			dp[i][1] = 2 * b + min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a);
		}
		else {
			if (s[i - 1] == '0') {
				dp[i][0] = b + min(dp[i - 1][1] + 2 * a, dp[i - 1][0] + a);
			}
			dp[i][1] = 2 * b + min(dp[i - 1][1] + a, dp[i - 1][0] + 2 * a);
		}
	}
	dp[n][0] = b + min(dp[n - 1][0] + a, dp[n - 1][1] + 2 * a);
	return dp[n][0];
}

signed main() {
	FAST;
	FIXED;
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b >> s;
		cout << get() << '\n';
	}
	return 0;
}