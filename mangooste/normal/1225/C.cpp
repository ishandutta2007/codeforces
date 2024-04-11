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

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	ll n, p;
	cin >> n >> p;
	for (ll i = 1; i < 5e6; i++) {
		ll now = abs(n - i * p);
		int cnt = 0;
		while (now > 0) {
			if (now % 2 == 1) {
				cnt++;
			}
			now /= 2;
		}
		if (n - p * i >= i && cnt <= i) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
	return 0;
}