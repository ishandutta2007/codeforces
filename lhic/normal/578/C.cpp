#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const int MAXN = 220000;

ld arr[MAXN];
ld ss[MAXN];
int n;

ld check(ld x) {
	for (int i = 0; i < n; ++i) {
		arr[i] += x;
	}
	ss[0] = 0;
	ld mn = 0;
	ld mx = 0;
	for (int i = 0; i < n; ++i) {
		ss[i + 1] = ss[i] + arr[i];
		mn = min(mn, ss[i + 1]);
		mx = max(mx, ss[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		arr[i] -= x;
	}
	return mx - mn;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	ld l = -10100;
	ld r = 10100;
	for (int kk = 0; kk < 90; ++kk) {
		ld x1 = l + 4 * (r - l) / 9;
		ld x2 = x1 + (r - l) / 9;
		if (check(x1) < check(x2))
			r = x2;
		else
			l = x1;
	}
	cout.setf(ios::fixed);
	cout.precision(16);
	cout << check((l + r) / 2) << "\n";
	return 0;
}