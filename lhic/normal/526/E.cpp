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

const int MAXN = 1200000;

ll ss;

pair<int, int> ans[MAXN];
int a[MAXN * 2];
int n, q;

int solve(ll x) {
	if (ss <= x)
		return 1;
	ll sum = ss;
	int aa = n;
	int l = -1;
	for (int i = n; i < 2 * n; ++i) {
		sum += a[i];
		while (sum > x)
			++l, sum -= a[l];
		if (l < n)
			ans[i - n] = make_pair(1, l);
		else {
			ans[i - n] = ans[l - n];
			++ans[i - n].first;
		}
		//cout << i << " " << l << " " << ans[i - n].first << " " << ans[i - n].second << "\n";
		if (ans[i - n].second <= i - n)
			aa = min(aa, ans[i - n].first);
	}
	return aa;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), ss += a[i];
	memcpy(a + n, a, sizeof(a[0]) * n);
	for (int i = 0; i < q; ++i) {
		ll b;
		cin >> b;
		cout << solve(b) << "\n";
	}
	return 0;
}