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
typedef double ld;

using namespace std;

int n;
ll A;
int ca;
int cm;
ll m;
vector<pair<ll, int> > vv;
int ans[120000];
ll sum = 0;
ll pr[120000];
int a[120000];

int main() {
	scanf("%d%lld%d%d%lld", &n, &A, &ca, &cm, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), sum += A - a[i];
	if (sum <= m) {
		printf("%lld\n", cm * A + ca * n);
		for (int i = 0; i < n; ++i)
			printf("%lld ", A);
		return 0;
	}
	for (int i = 0; i < n; ++i)
		vv.push_back(make_pair(a[i], i));
	sort(vv.begin(), vv.end());
	pr[0] = 0;
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + vv[i].first;
	ll bst = -1;
	int bstp = 0;
	int bstmn = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (m < 0)
			break;
		int l = 0;
		int r = i + 1;
		while (r - l > 1) {
			int mm = (l + r) >> 1;
			if (vv[mm].first * mm - pr[mm] <= m)
				l = mm;
			else
				r = mm;
		}
		ll m2 = m - vv[l].first * l + pr[l];
		ll mn = min(A, vv[l].first + m2 / (l + 1));
		ll bst2 = (ll)cm * mn + (ll)ca * (n - i - 1);
		if (bst2 > bst)
			bst = bst2, bstp = i, bstmn = mn;
		m -= A - vv[i].first;
	}
	printf("%lld\n", bst);
	for (int i = bstp + 1; i < n; ++i)
		ans[vv[i].second] = A;
	for (int i = 0; i <= bstp; ++i)
		ans[vv[i].second] = max(vv[i].first, (ll)bstmn);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}