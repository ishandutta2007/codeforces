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

const int n = 5e5 + 1;
const int k = 299;

vector <int> a(n, 0);
vector <vector <int>> ans(k, vector <int>(k, 0));

signed main() {
	FAST;
	FIXED;
	int q;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 2) {
			if (x < k) {
				cout << ans[x][y] << '\n';
			}
			else {
				int ans_now = 0;
				for (int i = y; i < n; i += x) {
					ans_now += a[i];
				}
				cout << ans_now << '\n';
			}
		}
		else {
			a[x] += y;
			for (int i = 1; i < k; i++) {
				ans[i][x % i] += y;
			}
		}
	}
	return 0;
}