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
const int MAXN = 120000;
vector<tuple<int, int, int> > vv;
vector<int> cl[MAXN];
vector<pair<int, int> > gg[MAXN];
int fv[MAXN];
int fv1[MAXN];
int n, k;

int get(int x) {
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fv[x];
	return ans;
}

int get1(int x) {
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fv1[x];
	return ans;
}

void add(int x, int d) {
	for (; x < vv.size(); x |= (x + 1))
		fv[x] += d;
}

void add1(int x, int d) {
	for (; x < vv.size(); x |= (x + 1))
		fv1[x] += d;
}
ll solve() {
	ll ans = 0;
	sort(vv.begin(), vv.end());
	memset(fv, 0, sizeof(fv[0]) * vv.size());
	memset(fv1, 0, sizeof(fv1[0]) * vv.size());
	for (int i = 0; i < vv.size(); ++i)
		cl[i].clear();
	for (int i = (int)vv.size() - 1; i >= 0; --i) {
		for (int j: cl[i]) {
			add(j, -1);
			if (get<2>(vv[j]) == 1)
				add1(j, -1);
		}
		int x, r, t;
		tie(x, r, t) = vv[i];
		int nx = lower_bound(vv.begin(), vv.end(), make_tuple(x + r + 1, 0, 0)) - vv.begin();
		--nx;
		if (t == 1)
			ans += get(nx);
		else
			ans += get1(nx);
		int pr = lower_bound(vv.begin(), vv.end(), make_tuple(x - r, 0, 0)) - vv.begin();
		--pr;
		if (pr >= 0)
			cl[pr].push_back(i);
		add(i, 1);
		if (t == 1)
			add1(i, 1);
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		int x, r, f;
		scanf("%d%d%d", &x, &r, &f);
		gg[f].push_back(make_pair(x, r));
	}
	ll ans = 0;
	for (int i = 0; i <= 10000; ++i) {
		if (gg[i].empty())
			continue;
		vv.clear();
		for (auto j: gg[i])
			vv.push_back(make_tuple(j.first, j.second, 1));
		for (int l = i + 1; l <= i + k; ++l) {
			for (auto j: gg[l])
				vv.push_back(make_tuple(j.first, j.second, 0));
		}
		ans += solve();
	}
	cout << ans << "\n";
	return 0;
}