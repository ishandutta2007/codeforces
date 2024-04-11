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

const int MAXN = 210000;

int n;
ll a[MAXN];
ll sum[MAXN];
ll sum2[MAXN];
ll ans = 0;
ll k[MAXN];
ll b[MAXN];

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first != b.first ? a.first > b.first : a.second > b.second;
}

void run(int l, int r) {
	if (l + 1 == r) {
		ans = max(ans, a[l]);
		return;
	}
	int m = (l + r) >> 1;
	run(l, m);
	run(m, r);
	vector<pair<ll, ll> > vv;
	for (int i = m; i < r; ++i)
		vv.push_back(make_pair(k[i], b[i]));
	sort(vv.begin(), vv.end(), cmp);
	vector<pair<ll, ll> > vv2;
	for (int i = 0; i < (int)vv.size(); ++i) {
		while (!vv2.empty() && vv2.back().second >= vv[i].second)
			vv2.pop_back();
		while ((int)vv2.size() >= 2 && (vv[i].first - vv2[vv2.size() - 2].first) / (ld)(vv2[vv2.size() - 1].first - vv2[vv2.size() - 2].first) >= (vv[i].second - vv2[vv2.size() - 2].second) / (ld)(vv2[vv2.size() - 1].second - vv2[vv2.size() - 2].second))
			vv2.pop_back();
		vv2.push_back(vv[i]);
	}
	int now = 0;
	for (int i = l; i < m; ++i) {
		while (now < (int)vv2.size() - 1 && vv2[now].first * i + vv2[now].second >= vv2[now + 1].first * i + vv2[now + 1].second)
			++now;
		ans = max(ans, sum2[i] - (vv2[now].first * i + vv2[now].second));
	}
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = n - 1; i >= 0; --i)
		sum[i] = sum[i + 1] + a[i];
	for (int i = n - 1; i >= 0; --i)
		sum2[i] = sum2[i + 1] + sum[i], ans = max(ans, sum2[i]);
	for (int i = 0; i < n; ++i)
		k[i] = -sum[i], b[i] = sum2[i] + sum[i] * i;
	run(0, n);
	cout << ans << "\n";
	return 0;
}