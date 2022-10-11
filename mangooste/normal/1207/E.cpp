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

signed main() {
	FAST;
	FIXED;
	cout << "? ";
	for (int i = 1; i <= 100; i++) {
		cout << i << ' ';
	}
	cout << endl;
	int ans1; cin >> ans1; ans1 /= 128;
	cout << "? ";
	for (int i = 1; i <= 100; i++) {
		cout << i * 128 << ' ';
	}
	cout << endl;
	int ans2; cin >> ans2; ans2 %= 128;
	cout << "! " << ans1 * 128 + ans2 << endl;
	return 0;
}