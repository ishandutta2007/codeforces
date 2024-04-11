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

vector <vector <int>> a, b;
int n, m;

bool check(int i, int j) {
	return a[i][j] == 1 && a[i + 1][j + 1] == 1
		&& a[i + 1][j] == 1 && a[i][j + 1] == 1;
}

signed main() {
	FAST;
	FIXED;
	cin >> n >> m;
	a.resize(n, vector <int>(m));
	b.resize(n, vector <int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (check(i, j)) {
				ans.pb(mp(i + 1, j + 1));
				b[i][j] = 1, b[i + 1][j] = 1, b[i][j + 1] = 1, b[i + 1][j + 1] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << sz(ans) << '\n';
	for (auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
	return 0;
}