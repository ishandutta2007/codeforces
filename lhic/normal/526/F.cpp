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
const int MAXN = 310000;

int n;
int a[MAXN];
int cc[MAXN * 2];

ll solve(const vector<pair<int, int> > &vvl, const vector<pair<int, int> > &vvr) {
	int now = 0;
	ll ans = 0;
	for (int i = 0; i < (int)vvl.size(); ++i) {
		while (now + 1 < (int)vvr.size() && vvr[now + 1].first > vvl[i].first && vvr[now + 1].second < vvl[i].second)
			++now;
		if (vvr[now].first > vvl[i].first && vvr[now].second < vvl[i].second && i + now + 1 == vvl[i].second - vvl[i].first)
			++ans;
	}
	int now1 = 0;
	int now2 = -1;
	for (int i = 0; i < (int)vvl.size(); ++i) {
		while (now1 < (int)vvr.size() && vvl[i].first < vvr[now1].first)
			--cc[vvr[now1].first + now1 + 1], ++now1;
		while (now2 + 1 < (int)vvr.size() && vvl[i].second > vvr[now2 + 1].second)
			++now2, ++cc[vvr[now2].first + now2 + 1];
		ans += max(0, cc[vvl[i].second - i]);
	}
	for (int i = 0; i < (int)vvr.size(); ++i)
		cc[vvr[i].first + i + 1] = 0;
	return ans;
}

ll run(int l, int r) {
	if (l + 1 == r)
		return 1;
	int m = (l + r) >> 1;
	ll ans = run(l, m) + run(m, r);
	vector<pair<int, int> > vvl;
	vector<pair<int, int> > vvr;
	int mn = n;
	int mx = -1;
	for (int i = m - 1; i >= l; --i) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		vvl.push_back(make_pair(mn, mx));
	}
	mn = n;
	mx = -1;
	for (int i = m; i < r; ++i) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		vvr.push_back(make_pair(mn, mx));
	}
	ans += solve(vvl, vvr) + solve(vvr, vvl);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		a[x] = y;
	}
	cout << run(0, n) << "\n";
	return 0;
}