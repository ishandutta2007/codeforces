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

const int MAXN = 3000;

int n;
int x[MAXN];

int y[MAXN];
vector<pair<int, int> > vv;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", x + i, y + i);
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dx < 0 || (dx == 0 && dy < 0))
				dx = -dx, dy = -dy;
			vv.push_back(make_pair(dx, dy));
		}
	sort(vv.begin(), vv.end());
	ll ans = 0;
	ll cnt = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		++cnt;
		if (i == (int)vv.size() - 1 || vv[i + 1] != vv[i]) {
			ans += cnt * (cnt - 1) / 2;
			cnt = 0;
		}
	}
	cout << ans / 2 << "\n";
	return 0;
}