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

const ll MX = 1e9 + 600;
int n, k;
vector<ll> vv;
vector<tuple<int, int, int> > ev;
ll ans[120000];
ll arr[220000];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x -= k - 1;
		y -= k - 1;
		vv.push_back(y);
		vv.push_back(y + k);
		ev.push_back(make_tuple(x, y, 0));
		ev.push_back(make_tuple(x + k, y, 1));
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	sort(ev.begin(), ev.end());
	int cnt = 0;
	for (int i = 0; i < (int)ev.size(); ++i) {
		int x, y, t;
		tie(x, y, t) = ev[i];
		int l = lower_bound(vv.begin(), vv.end(), y) - vv.begin();
		int r = lower_bound(vv.begin(), vv.end(), y + k) - vv.begin();
		if (t == 0)
			t = 1;
		else
			t = -1;
		for (int j = l; j < r; ++j) {
			++cnt;
			ans[arr[j]] -= (vv[j + 1] - vv[j]) * (MX - x);
			arr[j] += t;
			if (arr[j] != 0)
				ans[arr[j]] += (vv[j + 1] - vv[j]) * (MX - x);
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}