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
#include <unordered_map>


typedef long long ll;
typedef long double ld;

using namespace std;


struct q {
	int l, r, n, ans;
};

bool cmpr(q a, q b) {
	return a.r < b.r;
}

bool cmpn(q a, q b) {
	return a.n < b.n;
}

const int MAXN = 510000;
const int INF = MAXN;
int n;
int m;


q qq[MAXN];
unordered_map<int, int> mm;

int rmq[MAXN * 4];
int a[MAXN];

void build(int v, int tl, int tr) {
	rmq[v] = INF;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl + 1 == tr) {
		rmq[v] = y;
		return;
	}
	int m = (tl + tr) >> 1;
	if (x < m)
		upd(v * 2 + 1, tl, m, x, y);
	else
		upd(v * 2 + 2, m, tr, x, y);
	rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

int get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return INF;
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &qq[i].l, &qq[i].r), --qq[i].l, qq[i].n = i;
	sort(qq, qq + m, cmpr);
	int now = 0;
	build(0, 0, n);
	for (int i = 0; i < m; ++i) {
		while (now < qq[i].r) {
			if (mm.find(a[now]) != mm.end())
				upd(0, 0, n, mm[a[now]], now - mm[a[now]]);
			mm[a[now]] = now;
			++now;
		}
		qq[i].ans = get(0, 0, n, qq[i].l, qq[i].r);
	}
	sort(qq, qq + m, cmpn);
	for (int i = 0; i < m; ++i) {
		if (qq[i].ans == INF)
			printf("-1\n");
		else
			printf("%d\n", qq[i].ans);
	}
	return 0;
}