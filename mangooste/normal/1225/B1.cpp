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

typedef long long ll;
typedef long double ld;

using namespace std;

int run() {
	int n, k, d;
	cin >> n >> k >> d;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	int now = 0, ans = 1e9;
	map <int, int> m;
	for (int i = 0; i < d; i++) {
		if (m[a[i]] == 0)
			now++;
		m[a[i]]++;
	}
	ans = now;
	for (int i = d - 1; i < n; i++) {
		ans = min(ans, now);
		if (i != n - 1) {
			if (m[a[i + 1]] == 0) {
				now++;
			}
			m[a[i + 1]]++;
			if (m[a[i - d + 1]] == 1) {
				now--;
			}
			m[a[i - d + 1]]--;
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int q;
	cin >> q;
	while (q--)
		cout << run() << '\n';
	return 0;
}