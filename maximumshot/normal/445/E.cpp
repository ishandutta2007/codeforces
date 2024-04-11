#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

vec< ll > sum, delt;
vec< int > color;

void push(int v, int tl, int tr) {
	if(color[v]) color[v << 1] = color[v << 1 | 1] = color[v];
	int tm = (tl + tr) / 2;
	delt[v << 1] += delt[v];
	delt[v << 1 | 1] += delt[v];
	sum[v << 1] += 1ll * delt[v] * (tm - tl + 1);
	sum[v << 1 | 1] += 1ll * delt[v] * (tr - tm);
	delt[v] = 0;
}

void up(int v) {
	sum[v] = sum[v << 1] + sum[v << 1 | 1];
	delt[v] = 0;
	if(color[v << 1] == color[v << 1 | 1]) color[v] = color[v << 1];
	else color[v] = 0;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	if(l <= tl && tr <= r && color[v]) {
		delt[v] += abs(x - color[v]);
		sum[v] += 1ll * (tr - tl + 1) * abs(x - color[v]);
		color[v] = x;
	}else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		if(l <= tm) upd(v << 1, tl, tm, l, r, x);
		if(r > tm) upd(v << 1 | 1, tm + 1, tr, l, r, x);
		up(v);
	}
}

ll get(int v, int tl, int tr, int l, int r) {
	if(l <= tl && tr <= r) return sum[v];
	else {
		int tm = (tl + tr) / 2;
		push(v, tl, tr);
		ll ans = 0;
		if(l <= tm) ans += get(v << 1, tl, tm, l, r);
		if(r > tm) ans += get(v << 1 | 1, tm + 1, tr, l, r);
		up(v);
		return ans;
	}
}

void build(int v, int tl, int tr) {
	if(tl == tr) color[v] = tl;
	else {
		int tm = (tl + tr) / 2;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
	}
}

bool solve() {

	int n, m;
	
	scanf("%d %d", &n, &m);

	sum.resize(4 * n);
	delt.resize(4 * n);
	color.resize(4 * n);

	build(1, 1, n);

	for(int ty, l, r, x;m;m--) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d %d %d", &l, &r, &x);
			upd(1, 1, n, l, r, x);
		}else {
			scanf("%d %d", &l, &r);
			printf("%I64d\n", get(1, 1, n, l, r));
		}

		//print(1, 1, n);
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}