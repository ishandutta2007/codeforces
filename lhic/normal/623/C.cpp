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

int n;
struct point {
	ll x, y;
};

bool cmp(point a, point b) {
	if (a.x < b.x)
		return 1;
	if (a.x > b.x)
		return 0;
	return a.y < b.y;
}

point arr[120000];
ll gol[120000];
ll gor[120000];

int check(ll d) {
	ll l = 100000000;
	ll r = -l;
	ll l2 = 100000000;
	ll r2 = -l2;
	for (int i = 0; i < n; ++i)
		l2 = min(l2, arr[i].y), r2 = max(r2, arr[i].y);
	if ((r2 - l2) * (r2 - l2) <= d)
		return 1;
	l2 = 100000000;
	r2 = -l2;
	for (int i = 0; i < n; ++i)
		l2 = min(l2, arr[i].x), r2 = max(r2, arr[i].x);
	if ((r2 - l2) * (r2 - l2) <= d)
		return 1;
	if (arr[0].x > 0)
		return 0;
	int now = n - 1;
	gol[n - 1] = l;
	gor[n - 1] = r;
	for (int i = n - 2; i >= 0; --i)
		gol[i] = min(gol[i + 1], arr[i + 1].y), gor[i] = max(gor[i + 1], arr[i + 1].y);
	for (int i = 0; i < n; ++i) {
		if (arr[i].x > 0)
			break;
		while (arr[now].x > 0 && arr[now].x > abs(arr[i].x))
			--now;
		while (arr[now].x > 0 && (arr[i].x - arr[now].x) * (arr[i].x - arr[now].x) > d)
			--now;
		while (now < n - 1 && arr[now + 1].x <= abs(arr[i].x) && (arr[i].x - arr[now + 1].x) * (arr[i].x - arr[now + 1].x) <= d)
			++now;
		
		ll l2 = min(l, gol[now]);
		ll r2 = max(r, gor[now]);
		if (arr[i].x * arr[i].x <= d) {
			ll xx = max(abs(l2), abs(r2));
			if (l2 > r2 || (arr[i].x * arr[i].x + xx * xx) <= d) {
				if (l2 > r2 || (r2 - l2) * (r2 - l2) <= d) {
					return 1;
				}
			}
		}
		l = min(l, arr[i].y);
		r = max(r, arr[i].y);
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", &arr[i].x, &arr[i].y);
	sort(arr, arr + n, cmp);
	ll l = -1;
	ll r = 4 * 100000000ll * 100000000ll;
	while (r - l > 1) {
		ll m = (l + r) >> 1;
		if (check(m)) {
			r = m;
			continue;
		}
		for (int i = 0; i < n; ++i)
			arr[i].x = -arr[i].x, arr[i].y = -arr[i].y;
		reverse(arr, arr + n);
		if (check(m))
			r = m;
		else
			l = m;
	}
	cout << r << "\n";
	return 0;
}