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

typedef long long ll;
typedef long double ld;

using namespace std;

signed main() {
	FAST;
	FIXED;
	int n; cin >> n;
	vector <ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <vector <ll>> dp(n, vector <ll>(2));
	dp[0][0] = abs(1 - a[0]), dp[0][1] = abs(-1 - a[0]);
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][0] + abs(1 - a[i]), dp[i - 1][1] + abs(-1 - a[i]));
		dp[i][1] = min(dp[i - 1][0] + abs(-1 - a[i]), dp[i - 1][1] + abs(1 - a[i]));
	}
	cout << dp[n - 1][0];
	return 0;
}