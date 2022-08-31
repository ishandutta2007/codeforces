#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <memory>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime> 
#include <stack>
#include <iostream>
#include <functional>
#include <fstream>

#define mp make_pair
#define pb push_back

using ll = long long;
using ld = long double;

using namespace std;

const int MAXN = 200001;
int a[MAXN], b[MAXN];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cout.setf(ios::fixed); cout.precision(20);
	int n, p;
	cin >> n >> p;
	ld lg = 0, rg = 1e+12;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		s += a[i];
	}
	if (s <= p) {
		cout << -1 << endl;
		return 0;
	}
	for (int iter = 0; iter < 200; iter++) {
		ld md = (lg + rg) / 2.0;
		ld c = md * (ld)p;
		for (int i = 0; i < n; i++) {
			c -= max((ld)0.0, ((ld)a[i] * md - (ld)b[i]));
		}
		if (c >= 0) lg = md;
		else rg = md;
	}
	cout << (lg + rg) / 2.0 << endl;
	return 0;
}