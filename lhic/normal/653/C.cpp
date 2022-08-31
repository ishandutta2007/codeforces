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
int a[220000];
int nw[220000];
int sm = 0;

int bd(int x) {
	if (x == n - 1)
		return 0;
	if (x % 2 == 0 && a[x + 1] <= a[x])
		return 1;
	if (x % 2 == 1 && a[x + 1] >= a[x])
		return 1;
	return 0;
}

void init() {
	for (int i = 0; i < n; ++i)
		nw[i] = bd(i), sm += nw[i];
}

void upd(int x) {
	sm += bd(x) - nw[x];
	nw[x] = bd(x);
	if (x > 0) {
		sm += bd(x - 1) - nw[x - 1];
		nw[x - 1] = bd(x - 1);
	}
}

int tr(int x, int y) {
	swap(a[x], a[y]);
	upd(x);
	upd(y);
	int ans = 0;
	if (sm == 0)
		ans = 1;
	swap(a[x], a[y]);
	upd(x);
	upd(y);
	return ans;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	init();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			if (a[i + 1] <= a[i]) {
				int ans = 0;
				for (int j = 0; j < n; ++j) {
					ans += tr(i, j);
					ans += tr(i + 1, j);
				}
				ans -= tr(i, i + 1);
				cout << ans << "\n";
				return 0;
			}
		}
		else {
			if (a[i + 1] >= a[i]) {
				int ans = 0;
				for (int j = 0; j < n; ++j) {
					ans += tr(i, j);
					ans += tr(i + 1, j);
				}
				ans -= tr(i, i + 1);
				cout << ans << "\n";
				return 0;
			}
		}
	}
	return 0;
}