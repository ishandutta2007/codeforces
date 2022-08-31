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

const ld eps = 1e-12;

vector<ld> gg;

struct point {
	ld x, y;
	point() {}
	point(ld x, ld y) : x(x), y(y) {}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
};

vector<point> vv;
vector<point> vv2;


int solve() {
	gg.clear();
	int ccv = 0;
	int cce = 0;
	for (int i = 0; i < (int)vv2.size(); ++i) {
		if (abs(vv2[i].x) > eps)
			gg.push_back(vv2[i].y / vv2[i].x);
		else if (abs(vv2[i].y) > eps)
			++ccv;
		else
			++cce;
	}
	ll ans = 0;
	assert(cce <= 1);
	if (cce)
		ans += (int)vv2.size() - 1;
	ans += ccv * (ccv - 1) / 2;
	sort(gg.begin(), gg.end());
	int cnt = 0;
	for (int i = 0; i < (int)gg.size(); ++i) {
		++cnt;
		if (i == (int)gg.size() - 1 || abs(gg[i] - gg[i + 1]) > eps)
			ans += cnt * (cnt - 1) / 2, cnt = 0;
	}
	return ans;
}

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		point x;
		x.x = (ld)a * (ld)c / (a * a + b * b);
		x.y = (ld)b * (ld)c / (a * a + b * b);
		vv.push_back(x);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		vv2.clear();
		for (int j = i + 1; j < n; ++j)
			vv2.push_back(vv[j] - vv[i]);
		ans += solve();
	}
	cout << ans << "\n";
	return 0;
}