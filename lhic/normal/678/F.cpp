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
const ll INF = 1e18 * 1.1;
int n;
int tt[MAXN];
pair<ll, ll> pr[MAXN];
ll qq[MAXN];

vector<pair<ll, ll> > vv[MAXN * 4];

void add(int v, int tl, int tr, int l, int r, pair<ll, ll> x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		vv[v].push_back(x);
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
}

vector<pair<ll, ll> > vv2;

void build(int v, int tl, int tr) {
	sort(vv[v].begin(), vv[v].end());
	vv2.clear();
	for (int i = 0; i < (int)vv[v].size(); ++i) {
		while (!vv2.empty() && vv2.back().first == vv[v][i].first)
			vv2.pop_back();
		while ((int)vv2.size() >= 2 && (vv[v][i].first - vv2[vv2.size() - 2].first) * (vv2.back().second - vv2[vv2.size() - 2].second) <= (vv[v][i].second - vv2[vv2.size() - 2].second) * (vv2.back().first - vv2[vv2.size() - 2].first))
			vv2.pop_back();
		vv2.push_back(vv[v][i]);
	}
	vv[v] = vv2;


	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}


ll get2(const vector<pair<ll, ll> >& vv, ll q) {
	if (vv.empty())
		return -INF;
	int l = 0;
	int r = (int)vv.size();
	while (r - l > 1) {
		int m = (l + r) >> 1;
		if (vv[m - 1].first * q + vv[m - 1].second >= vv[m].first * q + vv[m].second)
			r = m;
		else
			l = m;
	}
	return vv[l].first * q + vv[l].second;
}


ll get(int v, int tl, int tr, int k, ll q) {
	ll ans = get2(vv[v], q);
	if (tl + 1 == tr)
		return ans;
	int m = (tl + tr) >> 1;
	if (k < m)
		ans = max(ans, get(v * 2 + 1, tl, m, k, q));
	else
		ans = max(ans, get(v * 2 + 2, m, tr, k, q));
	return ans;
}


int fl[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", tt + i);
		if (tt[i] == 1) {
			scanf("%lld%lld", &pr[i].first, &pr[i].second);
		}
		else if (tt[i] == 3) {
			scanf("%lld", qq + i);
		}
		else {
			int k;
			scanf("%d", &k);
			--k;
			add(0, 0, n, k, i, pr[k]);
			fl[k] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (tt[i] == 1 && !fl[i])
			add(0, 0, n, i, n, pr[i]);
	}
	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		if (tt[i] == 3) {
			ll ans = get(0, 0, n, i, qq[i]);
			if (ans != -INF)
				printf("%lld\n", get(0, 0, n, i, qq[i]));
			else
				printf("EMPTY SET\n");
		}
	}
	return 0;
}