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
	int da, db;
	cin >> da >> db;
	if (da == db) {
		cout << da << "0 " << db << "1\n";
		return 0;
	}
	if (db == da + 1) {
		cout << da << "9 " << db << "0\n";
		return 0;
	}
	if (db == 1 && da == 9) {
		cout << da << ' ' << db << "0\n";
		return 0;
	}
	cout << "-1\n";
	return 0;
}