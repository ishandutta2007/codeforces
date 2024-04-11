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
#include <queue>

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

vec< vec< int > > t;  

void up(int v) {
	int ls, rs, i1, i2;
	ls = v * 2 + 1;
	rs = v * 2 + 2;
	i1 = i2 = 0;
	while(i1 < (int)t[ls].size() && i2 < (int)t[rs].size()) {
		if(t[ls][i1] < t[rs][i2]) t[v].push_back(t[ls][i1++]);
		else t[v].push_back(t[rs][i2++]);
	}
	while(i1 < (int)t[ls].size()) t[v].push_back(t[ls][i1++]);
	while(i2 < (int)t[rs].size()) t[v].push_back(t[rs][i2++]);
}

void build(const vec< pii > & a, int v, int tl, int tr) {
	if(tl == tr) t[v].push_back(a[tl].first);
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2 + 1, tl, tm);
		build(a, v * 2 + 2, tm + 1, tr);
		up(v);
	}
}

int get(int v, int tl, int tr, int l, int r, int lx, int rx) {
	if(l <= tl && tr <= r) {
		int ql, qr;
		ql = lower_bound(ALL(t[v]), lx) - t[v].begin();
		qr = upper_bound(ALL(t[v]), rx) - t[v].begin() - 1;
		return max(0, qr - ql + 1);
	}else {
		int tm = (tl + tr) / 2, ans = 0;
		if(l <= tm) ans += get(v * 2 + 1, tl, tm, l, r, lx, rx);
		if(r > tm) ans += get(v * 2 + 2, tm + 1, tr, l, r, lx, rx);
		return ans;
	}
}

bool solve() {

	int n, m;

	scanf("%d %d", &n, &m);

	vec< pii > a(n);
	for(int i = 0;i < n;i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	sort(ALL(a), [](const pii & p1, const pii & p2) {
		return ((p1.second < p2.second) || (p1.second == p2.second && p1.first < p2.first));
	});

	t.resize(4 * n);

	build(a, 0, 0, n - 1);
	
	for(int c;m;m--) {
		scanf("%d", &c);
		int ans = 0, l = -inf;
		for(int x;c;c--) {
			scanf("%d", &x);
			// [l .. x]

			int bl, br, bm, bp;
			bl = 0, br = n - 1;

			while(br - bl > 1) {
				bm = (bl + br) / 2;
				if(a[bm].second >= x) br = bm;
				else bl = bm + 1;
			}

			bp = (a[bl].second >= x?bl : (a[br].second >= x?br : n));
			// [bp .. n - 1]

			if(bp < n) ans += get(0, 0, n - 1, bp, n - 1, l, x);

			l = x + 1;
		} 

		printf("%d\n", ans);
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}