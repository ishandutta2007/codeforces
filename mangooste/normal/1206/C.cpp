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
	if (!(n % 2)) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector <int> ans(2 * n + 1);
	for (int i = 1; i <= n; ++i) {
		ans[i] = 2 * i - 1;
	}
	for (int i = 1; i <= n; ++i) {
		ans[n + i] = 2 * i;
	}
	for (int i = 2; i <= n; i += 2) {
		swap(ans[i], ans[n + i]);
	}
	for (int i = 1; i <= 2 * n; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}