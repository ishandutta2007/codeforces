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

const int MAXN = 300000;
int n;

vector<pair<int, int> > vv;
vector<pair<int, int> > vv2;

map<int, int> pl;

int ans;

int rmq[MAXN * 4];

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl + 1 == tr) {
		rmq[v] = y;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	rmq[v] = max(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		vv.push_back({a, b});
		vv2.push_back({a + b, a});
	}
	sort(vv.begin(), vv.end());
	sort(vv2.begin(), vv2.end());
	for (int i = 0; i < (int)vv2.size(); ++i)
		pl[vv2[i].second] = i;

	for (int i = 0; i < n; ++i) {
		int x = lower_bound(vv2.begin(), vv2.end(), make_pair(vv[i].first - vv[i].second + 1, 0)) - vv2.begin();
		int cc = get(0, 0, n, 0, x) + 1;
		ans = max(cc, ans);
		upd(0, 0, n, pl[vv[i].first], cc);
	}

	cout << ans;



	

	return 0;
}