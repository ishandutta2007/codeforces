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


const ll INF = 1e13;
const int MAXN = 510000;
const int CC = MAXN;
const ll MOD = 1000000007;

int q, n, m;
ll gx, gy;
ll xmx, xmn, ymx, ymn;
ll gox[MAXN + CC];
ll goy[MAXN + CC];
char s[MAXN];

ll getx2(ll d) {
	if (abs(d) > q)
		return INF;
	return gox[d + CC];
}

ll getx(ll d) {
	if (d == 0)
		return 0;
	if (d > 0) {
		if (gx > 0) {
			int l = -1;
			int r = MAXN;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (gx * m + xmx >= d)
					r = m;
				else
					l = m;
			}
			return (ll)r * q + getx2(d - gx * r);
		}
		else
			return getx2(d);

	}
	else {
		if (gx < 0) {
			int l = -1;
			int r = MAXN;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (gx * m + xmn <= d)
					r = m;
				else
					l = m;
			}
			return (ll)r * q + getx2(d - gx * r);
		}
		else
			return getx2(d);
	}
}

ll gety2(ll d) {
	if (abs(d) > q)
		return INF;
	return goy[d + CC];
}

ll gety(ll d) {
	if (d == 0)
		return 0;
	if (d > 0) {
		if (gy > 0) {
			int l = -1;
			int r = MAXN;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (gy * m + ymx >= d)
					r = m;
				else
					l = m;
			}
			return (ll)r * q + gety2(d - gy * r);
		}
		else
			return gety2(d);

	}
	else {
		if (gy < 0) {
			int l = -1;
			int r = MAXN;
			while (r - l > 1) {
				int m = (l + r) >> 1;
				if (gy * m + ymn <= d)
					r = m;
				else
					l = m;
			}
			return (ll)r * q + gety2(d - gy * r);
		}
		else
			return gety2(d);
	}
}

void init() {
	for (int i = -q; i <= q; ++i)
		gox[i + CC] = goy[i + CC] = INF;
	int nx = 0;
	int ny = 0;
	gox[nx + CC] = 0;
	goy[ny + CC] = 0;
	for (int i = 0; i < q; ++i) {
		if (s[i] == 'U')
			--nx;
		else if (s[i] == 'D')
			++nx;
		else if (s[i] == 'L')
			--ny;
		else
			++ny;
		gox[nx + CC] = min(gox[nx + CC], (ll)i + 1);
		goy[ny + CC] = min(goy[ny + CC], (ll)i + 1);
		xmx = max(xmx, (ll)nx);
		xmn = min(xmn, (ll)nx);
		ymx = max(ymx, (ll)ny);
		ymn = min(ymn, (ll)ny);
	}
	gx = nx;
	gy = ny;
}


int main() {
	scanf("%d%d%d", &q, &n, &m);
	scanf(" %s", s);
	init();
	int lx = 0;
	int rx = n - 1;
	int ly = 0;
	int ry = m - 1;
	ll ans = 0;
	while (rx >= lx && ry >= ly) {
		ll glx = getx(-(lx + 1));
		ll grx = getx(n - rx);
		ll gly = gety(-(ly + 1));
		ll gry = gety(m - ry);
		ll mn = glx;
		mn = min(mn, gly);
		mn = min(mn, grx);
		mn = min(mn, gry);
		if (mn >= INF) {
			printf("-1\n");
			return 0;
		}
		if (glx == mn) {
			ans = (ans + mn * (ry - ly + 1)) % MOD;
			++lx;
		}
		else if (grx == mn) {
			ans = (ans + mn * (ry - ly + 1)) % MOD;
			--rx;
		}
		else if (gly == mn) {
			ans = (ans + mn * (rx - lx + 1)) % MOD;
			++ly;
		}
		else if (gry == mn) {
			ans = (ans + mn * (rx - lx + 1)) % MOD;
			--ry;
		}
	}
	cout << ans << "\n";

	return 0;
}