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
	int n, ans = -1; cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		ans = max(ans, tmp);
	}
	cout << ans << ' ';
	ans = -1;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		ans = max(ans, tmp);
	}
	cout << ans << '\n';
	return 0;
}