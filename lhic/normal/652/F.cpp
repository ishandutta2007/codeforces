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
const int MAXN = 400000;

int n, m;
ll t;
int d[MAXN];
vector<pair<int, int> > vv;
vector<pair<int, int> > aa;
int ans[MAXN];


ll get(ll s, ll e, int d, ll t) {
	if (d == -1)
		swap(e, s);
	e -= s;
	e = (e + m) % m;
	t *= 2;
	if (e > t)
		return 0;
	t -= e;
	ll ans = 1 + t / m;
	return ans;
}


int main() {
	scanf("%d%d%lld", &n, &m, &t);
	for (int i = 0; i < n; ++i) {
		int p;
		char c;
		scanf("%d %c", &p, &c);
		if (c == 'R')
			d[i] = 1;
		else
			d[i] = -1;
		--p;
		aa.push_back(make_pair(((p + t * d[i]) % m + m) % m, d[i]));
		vv.push_back(make_pair(p, i));
	}
	sort(vv.begin(), vv.end());
	sort(aa.begin(), aa.end());
	int dd = d[vv[0].second];
	int st = vv[0].first;
	pair<int, int> gg = make_pair(((vv[0].first + t * d[vv[0].second]) % m + m) % m, d[vv[0].second]);
	for (int i = 0; i < n; ++i)
		if (aa[i] == gg) {
			rotate(aa.begin(), aa.begin() + i, aa.end());
			break;
		}
	ll sum = 0;
	for (int i = 1; i < (int)vv.size(); ++i) {
		if (d[vv[i].second] == dd)
			continue;
		sum += get(st, vv[i].first, dd, t);
	}
	sum %= n;
	if (dd == -1)
		sum = (n - sum) % n;
	rotate(vv.begin(), vv.begin() + sum, vv.end());
	for (int i = 0; i < n; ++i)
		ans[vv[i].second] = aa[i].first;
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}