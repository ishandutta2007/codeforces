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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 51000;

int n;
int a[MAXN];
int go[MAXN][30];
int mxx[MAXN];
vector<int> vv;
int us[MAXN * 30];
int ans[MAXN];

int main() {
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), mx = max(mx, a[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0;; ++j) {
			if ((a[i] >> j) != 0)
				vv.push_back(a[i] >> j);
			else
				break;
		}
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i = 0; i < n; ++i) {
		mxx[i] = 0;
		for (int j = 0;; ++j) {
			if ((a[i] >> j) != 0) {
				mxx[i] = j;
				go[i][j] = lower_bound(vv.begin(), vv.end(), (a[i] >> j)) - vv.begin();
			}
			else
				break;
		}
	}
	ll l = 0;
	ll r = mx;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		memset(us, 0, sizeof(us[0]) * (int)vv.size());
		int fl = 0;
		for (int i = 0; i < n; ++i) {
			int fl2 = 0;
			for (int j = 0; j <= mxx[i]; ++j) {
				if ((a[i] >> j) <= mid && !us[go[i][j]]) {
					fl2 = 1;
					us[go[i][j]] = 1;
					ans[i] = a[i] >> j;
					break;
				}
			}
			if (!fl2) {
				fl = 1;
				break;
			}
		}
		if (!fl)
			r = mid;
		else
			l = mid;
	}
	memset(us, 0, sizeof(us[0]) * (int)vv.size());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= mxx[i]; ++j) {
			if ((a[i] >> j) <= r && !us[go[i][j]]) {
				us[go[i][j]] = 1;
				ans[i] = a[i] >> j;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}