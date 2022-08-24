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
vector<pair<int, int> > vv[4];
int k;

void add(int c, int x, int n) {
	vv[c].push_back(make_pair(x, n));
	int now = vv[c].size() - 1;
	while (now > 0 && vv[c][now - 1] < vv[c][now])
		swap(vv[c][now], vv[c][now - 1]), --now;
	while ((int)vv[c].size() > k + 1)
		vv[c].pop_back();
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int x, y;
		x = x1 + x2;
		y = y2 + y1;
		add(0, x, i);
		add(1, y, i);
		add(2, -x, i);
		add(3, -y, i);
	}
	for (int i = 0; i < (int)vv[2].size(); ++i)
		vv[2][i].first = -vv[2][i].first;
	for (int i = 0; i < (int)vv[3].size(); ++i)
		vv[3][i].first = -vv[3][i].first;

	ll ans = 2e18;

	for (int i = 0; i < (int)vv[0].size(); ++i)
		for (int j = 0; j < (int)vv[1].size(); ++j)
			for (int t = 0; t < (int)vv[2].size(); ++t)
				for (int l = 0; l < (int)vv[3].size(); ++l) {
					ll dx = max(2, vv[0][i].first - vv[2][t].first);
					ll dy = max(2, vv[1][j].first - vv[3][l].first);
					if (dx & 1)
						++dx;
					if (dy & 1)
						++dy;
					dx >>= 1;
					dy >>= 1;
					if (dx * dy >= ans)
						continue;
					vector<int> gg;
					for (int it = 0; it < i; ++it)
						gg.push_back(vv[0][it].second);
					for (int it = 0; it < j; ++it)
						gg.push_back(vv[1][it].second);
					for (int it = 0; it < t; ++it)
						gg.push_back(vv[2][it].second);
					for (int it = 0; it < l; ++it)
						gg.push_back(vv[3][it].second);
					sort(gg.begin(), gg.end());
					gg.resize(unique(gg.begin(), gg.end()) - gg.begin());
					if ((int)gg.size() <= k)
						ans = dx * dy;
				}

	cout << ans << "\n";
	return 0;
}