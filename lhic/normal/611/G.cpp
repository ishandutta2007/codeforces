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
typedef unsigned long long ull;

using namespace std;

const int MAXN = 510000;
const ll MOD = 1000000007;

struct point {
	ll x, y;
	point() {}
	point(ll x, ll y) : x(x), y(y) {}
	point operator-(point a) {
		return {x - a.x, y - a.y};
	}
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
};

ll n;
point arr[MAXN * 2];

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &arr[i].x, &arr[i].y);
	reverse(arr, arr + n);
	for (int i = 0; i < n; ++i)
		arr[i + n] = arr[i];
	ll s = 0;
	for (int i = 0; i < n; ++i)
		s += arr[i] * arr[i + 1];

	ll ans = 0;
	ll sx = 0;
	ll sy = 0;
	int g = 0;
	ll nows = 0;
	ll nans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (g <= i) {
			sx = arr[i + 1].x;
			sy = arr[i + 1].y;
			nows = 0;
			nans = 0;
			g = i + 1;
		}
		while ((nows + (arr[g] - arr[i]) * (arr[g + 1] - arr[i])) <= s / 2) {
			nows += (arr[g] - arr[i]) * (arr[g + 1] - arr[i]);
			++g;
			sx += arr[g].x;
			sy += arr[g].y;
			nans = (nans + nows % MOD) % MOD;
			if ((ull)nows * 2ull == (ull)s)
				++cnt;
		}
		ans = (ans + nans) % MOD;
		nows -= (arr[i + 1] - arr[i]) * (arr[g] - arr[i]);
		ll go = (((arr[i + 1].x - arr[i].x) % MOD) * (sy % MOD - ((g - i) * arr[i].y) % MOD)) % MOD;
		go = (go + MOD) % MOD;
		nans = (nans - go + MOD) % MOD;
		go = (((arr[i + 1].y - arr[i].y) % MOD) * (sx % MOD - ((g - i) * arr[i].x) % MOD)) % MOD;
		go = (go + MOD) % MOD;
		nans = (nans + go + MOD) % MOD;
		sx -= arr[i + 1].x;
		sy -= arr[i + 1].y;
	}
	assert(cnt % 2 == 0);
	cnt /= 2;
	ans = (ans - (cnt * ( (s / 2) % MOD)) % MOD + MOD) % MOD;

	s %= MOD;
	s = ((((ll)n * (n - 3) / 2) % MOD) * s) % MOD;

	s = (s - 2 * ans + 2 * MOD) % MOD;
	cout << s << "\n";
	return 0;
}