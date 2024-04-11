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

const int MAXX = 501000;
const int MAXN = 201000;

int cnt[MAXX];
int xx[MAXX];
int cc[MAXX];
int en[MAXX];
int a[MAXN];

ll ans = 0;

int n;
int q;

void add(int x) {
	if (xx[x])
		return;
	if (cnt[x] & 1) {
		ans -= cc[x] * (cc[x] - 1) / 2;
		++cc[x];
		ans += cc[x] * (cc[x] - 1) / 2;
	}
	else {
		ans += cc[x] * (cc[x] - 1) / 2;
		++cc[x];
		ans -= cc[x] * (cc[x] - 1) / 2;
	}
}

void del(int x) {
	if (xx[x])
		return;
	if (cnt[x] & 1) {
		ans -= cc[x] * (cc[x] - 1) / 2;
		--cc[x];
		ans += cc[x] * (cc[x] - 1) / 2;
	}
	else {
		ans += cc[x] * (cc[x] - 1) / 2;
		--cc[x];
		ans -= cc[x] * (cc[x] - 1) / 2;
	}
}

int main() {
	xx[1] = 1;
	for (int i = 2; i < MAXX; ++i) {
		int x = i;
		for (int j = 2; j * j <= x; ++j) {
			if (x % j != 0)
				continue;
			if (x % (j * j) == 0) {
				xx[i] = 1;
				break;
			}
			x /= j;
			++cnt[i];
		}
		if (x != 1)
			++cnt[i];
	}
	scanf("%d%d", &n, &q);
	ll cou = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		if (en[x]) {
			en[x] = 0;
			--cou;
			for (int j = 1; j * j <= a[x]; ++j) {
				if (a[x] % j != 0)
					continue;
				del(j);
				if (j * j != a[x])
					del(a[x] / j);
			}
		}
		else {
			++cou;
			en[x] = 1;
			for (int j = 1; j * j <= a[x]; ++j) {
				if (a[x] % j != 0)
					continue;
				add(j);
				if (j * j != a[x])
					add(a[x] / j);
			}
		}
		printf("%I64d\n", cou * (cou - 1) / 2 - ans);
	}
	return 0;
}