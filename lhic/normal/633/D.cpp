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

int was[1200];
int us[1200];
int cnt[1200];
vector<int> vv;
map<int, int> mm;
int a[1200];
int n;
int go[1200][1200];
int tm;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), ++mm[a[i]];
	for (auto it: mm) {
		cnt[vv.size()] = it.second;
		vv.push_back(it.first);
	}
	n = vv.size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int x = vv[i] + vv[j];
			int y = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
			if (y == n || vv[y] != x)
				go[i][j] = -1;
			else
				go[i][j] = y;
		}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			++tm;
			was[i] = tm;
			was[j] = tm;
			us[i] = us[j] = 0;
			++us[i];
			++us[j];
			if (us[i] > cnt[i] || us[j] > cnt[j])
				continue;
			int now = 2;
			int x = i;
			int y = j;
			while (true) {
				int g = go[x][y];
				if (g == -1)
					break;
				if (was[g] != tm)
					was[g] = tm, us[g] = 0;
				if (cnt[g] <= us[g])
					break;
				++now;
				++us[g];
				x = y;
				y = g;
			}
			ans = max(ans, now);
		}

	cout << ans << "\n";

	return 0;
}