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
typedef long double ld;

using namespace std;

int n;
ld p[120];
ld a[120];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int pp;
		scanf("%d", &pp);
		p[i] = pp / 100.0;
	}
	for (int i = 0; i < n; ++i)
		a[i] = p[i];
	ld pp = 1;
	for (int j = 0; j < n; ++j) {
		pp *= a[j];
		if (pp < 1e-11)
			pp = 0;
	}
	ld ans = n * pp;
	ld lstp = pp;
	for (int i = n + 1; i < 1000000; ++i) {
		int bst = 0;
		ld bstp = 1 - p[0] + p[0] / a[0];
		for (int j = 1; j < n; ++j) {
			ld k = 1 - p[j] + p[j] / a[j];
			if (k > bstp)
				bst = j, bstp = k;
		}
		ld pp = 1;
		a[bst] += (1 - a[bst]) * p[bst];
		for (int j = 0; j < n; ++j) {
			pp *= a[j];
			if (pp < 1e-11)
				pp = 0;
		}
		ans += i * (pp - lstp);
		lstp = pp;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";
	return 0;
}