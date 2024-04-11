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

const int inf = 1e9;

signed main() {
	FAST;
	FIXED;
	int t; cin >> t;
	while (t--) {
		int b, p, f, h, c, ans = -inf;
		cin >> b >> p >> f >> h >> c;
		b /= 2;
		for (int i = 0; i <= p; i++) {
			int ans_now = 0;
			if (b >= i) {
				ans_now = h * min(i, p) + c * min(f, max(0, (b - min(i, p))));
			}
			else {
				ans_now = b * h;
			}
			ans = max(ans, ans_now);
		}
		cout << ans << '\n';
	}
	return 0;
}