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
const ll INF = 1e11;
const int MAXN = 120000;
ll a[MAXN];
ll go[MAXN];
ll m;
int n;

int check2(ll x, int g) {
	if (a[g] >= x)
		return 0;
	ll gg = a[g];
	for (int i = 0; i < g; ++i)
		gg = max(gg, a[i] + x);
	for (int i = g; i < n; ++i)
		go[i] = -INF;
	go[g] = gg;
	for (int i = g + 1; i < n; ++i) {
		gg = go[i - 1];
		if (gg >= a[i] - 1) {
			go[i] = max(go[i], max(gg, a[i] + x));
		}
		if (a[i] - x - 1 <= gg) {
			go[i] = max(go[i], a[i]);
		}
		if (i < n - 1 && a[i + 1] - x - 1 <= gg) {
			go[i + 1] = max(go[i + 1], a[i] + x);
		}
	}
	ll ggg = x - a[g];
	if (go[n - 1] + 1 + ggg >= m)
		return 1;
	else
		return 0;
}

int check(ll x) {
	return check2(x, 0) || check2(x, 1);
}


int main() {
	scanf("%lld", &m);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	if (n == m) {
		cout << 0 << "\n";
		return 0;
	}
	if (n == 1) {
		cout << m - 1 << "\n";
		return 0;
	}
	a[n] = a[0] + m;
	int mx = -1;
	int mxp = 0;
	for (int i = 0; i < n; ++i)
		if (a[i + 1] - a[i] > mx)
			mx = a[i + 1] - a[i], mxp = a[i + 1];
	for (int i = 0; i < n; ++i) {
		a[i] -= mxp;
		while (a[i] < 0)
			a[i] += m;
		while (a[i] >= m)
			a[i] -= m;
	}
	sort(a, a + n);
	ll l = 0;
	ll r = mx - 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
	return 0;
}