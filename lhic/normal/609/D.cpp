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

const int MAXN = 300000;

ll a[MAXN];
ll b[MAXN];
vector<pair<ll, int> > vv;
ll c[MAXN];
ll t[MAXN];
int n, m;
ll s;
int k;

int check(int mm) {
	ll ma = a[0];
	ll mb = b[0];
	for (int i = 0; i < mm; ++i)
		ma = min(ma, a[i]), mb = min(mb, b[i]);
	vv.clear();
	for (int i = 0; i < m; ++i)
		if (t[i] == 1)
			vv.push_back(make_pair(ma * c[i], i));
		else
			vv.push_back(make_pair(mb * c[i], i));
	sort(vv.begin(), vv.end());
	ll sum = 0;
	for (int i = 0; i < k; ++i)
		sum += vv[i].first;
	if (sum <= s)
		return 1;
	else
		return 0;
}


int main() {
	scanf("%d%d%d%lld", &n, &m, &k, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", b + i);
	}
	for (int i = 0; i < m; ++i)
		scanf("%lld%lld", t + i, c + i);
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int mm = (l + r) / 2;
		if (check(mm))
			r = mm;
		else
			l = mm;
	}
	if (r > n) {
		cout << -1 << "\n";
		return 0;
	}

	printf("%d\n", r);
	ll ma = a[0];
	ll mb = b[0];
	int ga = 0;
	int gb = 0;
	for (int i = 0; i < r; ++i) {
		if (a[i] < ma)
			ma = a[i], ga = i;
		if (b[i] < mb)
			mb = b[i], gb = i;
	}
	vv.clear();
	for (int i = 0; i < m; ++i)
		if (t[i] == 1)
			vv.push_back(make_pair(ma * c[i], i));
		else
			vv.push_back(make_pair(mb * c[i], i));
	sort(vv.begin(), vv.end());

	for (int i = 0; i < k; ++i) {
		int x = vv[i].second;
		if (t[x] == 1)
			printf("%d %d\n", x + 1, ga + 1);
		else
			printf("%d %d\n", x + 1, gb + 1);
	}

	return 0;
}