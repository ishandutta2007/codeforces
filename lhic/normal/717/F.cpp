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
const int MAXN = 210000;
const ll INF = 1e15;

ll rmq0[MAXN * 4];
ll rmq1[MAXN * 4];
ll dd0[MAXN * 4];
ll dd1[MAXN * 4];

ll a[MAXN];
ll b[MAXN];
int n;

void build0(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		if (tl % 2 == 0)
			rmq0[v] = b[tl];
		else
			rmq0[v] = INF;
		return;
	}
	int m = (tl + tr) >> 1;
	build0(v * 2 + 1, tl, m);
	build0(v * 2 + 2, m, tr);
	rmq0[v] = min(rmq0[v * 2 + 1], rmq0[v * 2 + 2]);
}

void build1(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		if (tl % 2 == 1)
			rmq1[v] = b[tl];
		else
			rmq1[v] = INF;
		return;
	}
	int m = (tl + tr) >> 1;
	build1(v * 2 + 1, tl, m);
	build1(v * 2 + 2, m, tr);
	rmq1[v] = min(rmq1[v * 2 + 1], rmq1[v * 2 + 2]);
}

void init() {
	b[0] = a[0];
	for (int i = 1; i < n; ++i)
		b[i] = a[i] - b[i - 1];
	build0(0, 0, n);
	build1(0, 0, n);
}

void add0(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd0[v] += d;
		rmq0[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add0(v * 2 + 1, tl, m, l, r, d);
	add0(v * 2 + 2, m, tr, l, r, d);
	rmq0[v] = min(rmq0[v * 2 + 1], rmq0[v * 2 + 2]) + dd0[v];
}

void add1(int v, int tl, int tr, int l, int r, ll d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd1[v] += d;
		rmq1[v] += d;
		return;
	}
	int m = (tl + tr) >> 1;
	add1(v * 2 + 1, tl, m, l, r, d);
	add1(v * 2 + 2, m, tr, l, r, d);
	rmq1[v] = min(rmq1[v * 2 + 1], rmq1[v * 2 + 2]) + dd1[v];
}

ll get0(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq0[v];
	int m = (tl + tr) >> 1;
	return min(get0(v * 2 + 1, tl, m, l, r), get0(v * 2 + 2, m, tr, l, r)) + dd0[v];
}

ll get1(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq1[v];
	int m = (tl + tr) >> 1;
	return min(get1(v * 2 + 1, tl, m, l, r), get1(v * 2 + 2, m, tr, l, r)) + dd1[v];
}

ll get(int x) {
	if (x < 0)
		return 0;
	if (x % 2 == 0)
		return get0(0, 0, n, x, x + 1);
	else
		return get1(0, 0, n, x, x + 1);
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	init();
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int t;
		int l, r;
		int k;
		scanf("%d%d%d", &t, &l, &r);
		++r;
		if (t == 1) {
			scanf("%d", &k);
			if (l % 2 == 0)
				add0(0, 0, n, l, r, k);
			else
				add1(0, 0, n, l, r, k);
			if ((r - l) % 2 != 0) {
				if (r % 2 == 0) {
					add0(0, 0, n, r, n, -k);
					add1(0, 0, n, r, n, k);
				}
				else {
					add1(0, 0, n, r, n, -k);
					add0(0, 0, n, r, n, k);
				}
			}
		}
		else {
			ll x = get(l - 1);
			if ((r - l) % 2 == 0) {
				if (get(r - 1) - x != 0) {
					printf("0\n");
					continue;
				}
				if (l % 2 == 0) {
					if (get0(0, 0, n, l, r) + x < 1) {
						printf("0\n");
						continue;
					}
					if (get1(0, 0, n, l, r) - x < 0) {
						printf("0\n");
						continue;
					}
				}
				else {
					if (get1(0, 0, n, l, r) + x < 1) {
						printf("0\n");
						continue;
					}
					if (get0(0, 0, n, l, r) - x < 0) {
						printf("0\n");
						continue;
					}
				}
			}
			else {
				if (get(r - 1) + x != 1) {
					printf("0\n");
					continue;
				}
				if (l % 2 == 0) {
					if (get0(0, 0, n, l, r) + x < 1) {
						printf("0\n");
						continue;
					}
					if (get1(0, 0, n, l, r) - x < 0) {
						printf("0\n");
						continue;
					}
				}
				else {
					if (get1(0, 0, n, l, r) + x < 1) {
						printf("0\n");
						continue;
					}
					if (get0(0, 0, n, l, r) - x < 0) {
						printf("0\n");
						continue;
					}
				}
			}
			printf("1\n");
		}
	}
	return 0;
}