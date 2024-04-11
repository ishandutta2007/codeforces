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

const ll MOD = 10000000000ll;

struct point {
	ll x, y;
	int n;
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
};

struct bigInt {
	ll a, b, c;
	bigInt() {
		a = 0;
		b = 0;
		c = 1;
	}
	bool operator<(bigInt x) {
		if (a < x.a || (a == x.a && b < x.b) || (a == x.a && b == x.b && c < x.c))
			return 1;
		return 0;
	}
	bigInt operator*(ll x) {
		bigInt ans = *this;
		ans.a *= x;
		ans.b *= x;
		ans.c *= x;
		ans.b += ans.c / MOD;
		ans.c %= MOD;
		ans.a += ans.b / MOD;
		ans.b %= MOD;
		return ans;
	}
};

bool cmp(point a, point b) {
	if (a.y >= 0 && b.y < 0)
		return true;
	if (a.y < 0 && b.y >= 0)
		return false;
	if (a.y == 0 && b.y == 0) {
		return (a.x > 0 && b.x < 0);
	}
	return a * b > 0;
}

int n;
point arr[200000];

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &arr[i].x, &arr[i].y), arr[i].n = i;
	sort(arr, arr + n, cmp);

	int x1 = -1;
	int x2 = -1;
	ll k1 = 0;
	ll a1, b1;
	arr[n] = arr[0];
	ll kk1 = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] * arr[i + 1] < 0)
			continue;
		ll k2 = arr[i] * arr[i + 1];
		ll a2 = arr[i].x * arr[i].x + arr[i].y * arr[i].y;
		ll b2 = arr[i + 1].x * arr[i + 1].x + arr[i + 1].y * arr[i + 1].y;
		ll kk2 = arr[i].x * arr[i + 1].x + arr[i].y * arr[i + 1].y;
		
		if (x1 == -1) {
			k1 = k2;
			a1 = a2;
			b1 = b2;
			x1 = arr[i].n;
			x2 = arr[i + 1].n;
			kk1 = kk2;
			continue;
		}
		bigInt f1;
		bigInt f2;
		f1 = f1 * k1;
		f1 = f1 * k1;
		f1 = f1 * a2;
		f1 = f1 * b2;
		f2 = f2 * k2;
		f2 = f2 * k2;
		f2 = f2 * a1;
		f2 = f2 * b1;


		
		if ((kk2 >= 0 && kk1 < 0) || (kk1 >= 0 && kk2 >= 0 && f2 < f1) || (kk1 < 0 && kk2 < 0 && f1 < f2)) {
			k1 = k2;
			a1 = a2;
			b1 = b2;
			x1 = arr[i].n;
			x2 = arr[i + 1].n;
			kk1 = kk2;
		}
	}

	cout << x1 + 1 << " " << x2 + 1 << "\n";

	return 0;
}