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


int k;
int n;
int cnt[1200000];
int a[320000];

ll nm(ll a) {
	if (a == k)
		return 0;
	else
		return a;
}

ll run(int l, int r) {
	if (l + 1 == r) {
		return 0;
	}
	int m = (l + r) / 2;
	ll ans = run(l, m) + run(m, r);
	int now = m - 1;
	int mx = 0;
	ll sum = 0;
	ll suml = 0;
	for (int i = m; i < r; ++i) {
		sum += a[i];
		if (a[i] < mx)
			continue;
		mx = a[i];

		while (now >= l && a[now] <= a[i]) {
			suml += a[now];
			suml %= k;
			++cnt[suml];
			--now;
		}


		ll sum2 = (sum - a[i]) % k;
		ans += cnt[nm(k - sum2)];
		for (int j = i + 1; j < r && a[j] < a[i]; ++j) {
			sum2 += a[j];
			sum2 %= k;
			ans += cnt[nm(k - sum2)];
		}
	}
	++now;
	while (now < m) {
		--cnt[suml];
		suml = (suml - (a[now] % k) + k) % k;
		++now;
	}

	now = m;
	mx = 0;
	sum = 0;
	suml = 0;
	for (int i = m - 1; i >= l; --i) {
		sum += a[i];
		if (a[i] < mx)
			continue;
		mx = a[i];

		while (now < r && a[now] < a[i]) {
			suml += a[now];
			suml %= k;
			++cnt[suml];
			++now;
		}


		ll sum2 = (sum - a[i]) % k;
		ans += cnt[nm(k - sum2)];
		for (int j = i - 1; j >= l && a[j] < a[i]; --j) {
			sum2 += a[j];
			sum2 %= k;
			ans += cnt[nm(k - sum2)];
		}
	}
	--now;
	while (now >= m) {
		--cnt[suml];
		suml = (suml - (a[now] % k) + k) % k;
		--now;
	}
	return ans;
}


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	cout << run(0, n);

	return 0;
}